// Copyright Epic Games, Inc. All Rights Reserved.

#include "GALAGA_USFX_2PPawn.h"
#include "GALAGA_USFX_2PProjectile.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Particles/ParticleSystem.h"
#include "Sound/SoundBase.h"

const FName AGALAGA_USFX_2PPawn::MoveForwardBinding("MoveForward");
const FName AGALAGA_USFX_2PPawn::MoveRightBinding("MoveRight");
const FName AGALAGA_USFX_2PPawn::FireForwardBinding("FireForward");
const FName AGALAGA_USFX_2PPawn::FireRightBinding("FireRight");

AGALAGA_USFX_2PPawn::AGALAGA_USFX_2PPawn()
{	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
	// Create the mesh component
	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);
	
	// Cache our sound effect
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
	FireSound = FireAudio.Object;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1200.f;
	CameraBoom->SetRelativeRotation(FRotator(-80.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm

	// campo de colision
	ShipCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision Player"));
	ShipCollision->SetCapsuleHalfHeight(80.0f);

	// creamos el efecto de explosion
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	if (ParticleAsset.Succeeded())
	{
		ShipExplosion = Cast<UParticleSystem>(ParticleAsset.Object);
	}

	// creando sonido de explosion
	static ConstructorHelpers::FObjectFinder<USoundBase> ExplosionAudioAA(TEXT("SoundWave'/Game/StarterContent/Audio/Explosion02.Explosion02'"));
	if (ExplosionAudioAA.Succeeded())
	{
		ExplosionSoundShip = ExplosionAudioAA.Object;
	}

	// Movement
	MoveSpeed = 1000.0f;
	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.1f;
	bCanFire = true;

	VidaP = 1000.0f;
}

void AGALAGA_USFX_2PPawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	// set up gameplay key bindings
	PlayerInputComponent->BindAxis(MoveForwardBinding);
	PlayerInputComponent->BindAxis(MoveRightBinding);
	PlayerInputComponent->BindAxis(FireForwardBinding);
	PlayerInputComponent->BindAxis(FireRightBinding);
}

void AGALAGA_USFX_2PPawn::Tick(float DeltaSeconds)
{
	// Find movement direction
	const float ForwardValue = GetInputAxisValue(MoveForwardBinding);
	const float RightValue = GetInputAxisValue(MoveRightBinding);

	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirection = FVector(ForwardValue, RightValue, 0.f).GetClampedToMaxSize(1.0f);

	// Calculate  movement
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
		
		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}
	}
	
	// Create fire direction vector
	const float FireForwardValue = GetInputAxisValue(FireForwardBinding);
	const float FireRightValue = GetInputAxisValue(FireRightBinding);
	const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.f);

	// Try and fire a shot
	FireShot(FireDirection);
}

void AGALAGA_USFX_2PPawn::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
	if (bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		if (FireDirection.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = FireDirection.Rotation();
			// Spawn projectile at an offset from this pawn
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// spawn the projectile
				World->SpawnActor<AGALAGA_USFX_2PProjectile>(SpawnLocation, FireRotation);
			}

			bCanFire = false;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AGALAGA_USFX_2PPawn::ShotTimerExpired, FireRate);

			// try and play the sound if specified
			if (FireSound != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
			}

			bCanFire = false;
		}
	}
}

void AGALAGA_USFX_2PPawn::ShotTimerExpired()
{
	bCanFire = true;
}

void AGALAGA_USFX_2PPawn::Damage(float Danio_)
{
	VidaP -= Danio_;
}

void AGALAGA_USFX_2PPawn::Componentes_Colision()
{
	//Efecto de Explosion 
	if (ShipExplosion)
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ShipExplosion, GetActorTransform());
	//Sonido de la explosion
	if (ExplosionSoundShip != nullptr)
		UGameplayStatics::PlaySoundAtLocation(this, ExplosionSoundShip, GetActorLocation());
	this->Destroy();
}

