// Fill out your copyright notice in the Description page of Project Settings.


#include "Proyectil_E.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/CapsuleComponent.h"
#include "Components/CapsuleComponent.h"
#include "Particles/ParticleSystem.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystem.h"
#include "Components/ShapeComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "GALAGA_USFX_2PPawn.h"

// Sets default values
AProyectil_E::AProyectil_E()
{
	PrimaryActorTick.bCanEverTick = true;

	// Creando la malla del proyectil
	Projectil_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectil_Mesh"));
	RootComponent = Projectil_Mesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (MeshAsset.Succeeded())
	{
		Projectil_Mesh->SetStaticMesh(MeshAsset.Object);

		//// Modificar la escala del componente de malla
		//FVector NewScale(-1.0f, -1.0f, -1.0f); // Escala modificada
		//Projectil_Mesh->SetWorldScale3D(NewScale);
	}


	// Inicializar el sistema de part�culas para la explosi�n
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	if (ParticleAsset.Succeeded())
	{
		Explosion_Particles = ParticleAsset.Object;
	}

	// Inicializar el sonido de la colisi�n
	static ConstructorHelpers::FObjectFinder<USoundBase> SoundAsset(TEXT("SoundWave'/Game/StarterContent/Audio/Explosion01.Explosion01'"));
	if (SoundAsset.Succeeded())
	{
		Projectil_Sound = SoundAsset.Object;
	}


	// Controlando el movimiento del proyectil
	Projectil_Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectil_Movement"));
	Projectil_Movement->InitialSpeed = 750.0f;
	Projectil_Movement->MaxSpeed = 850.0f;
	Projectil_Movement->bRotationFollowsVelocity = true;
	Projectil_Movement->bShouldBounce = false;
	Projectil_Movement->ProjectileGravityScale = 0.0f;

	// Creando el componente de colisi�n del proyectil
	Projectil_Collision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Projectil_Collision"));
	Projectil_Collision->SetupAttachment(RootComponent);

	// Estableciendo el tiempo de vida inicial del proyectil
	InitialLifeSpan = 5.f;

	// Da�o predeterminado del proyectil
	DanioProvocado = 0.f;
	//Configurando el proyectil para que genere eventos de colision
	Projectil_Collision->SetCapsuleHalfHeight(160.0f);
	Projectil_Collision->SetCapsuleRadius(160.0f);

}

// Called when the game starts or when spawned
void AProyectil_E::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProyectil_E::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProyectil_E::Set_Danio(float Danio)
{
	Danio_D_B = Danio;
}

void AProyectil_E::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	AGALAGA_USFX_2PPawn* Jugador = Cast<AGALAGA_USFX_2PPawn>(OtherActor);

	if (Jugador)
	{
		DestroyPROYECTIL();
		Jugador->Damage(Danio_D_B);
	}
}

void AProyectil_E::DestroyPROYECTIL()
{
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), Projectil_Sound, GetActorLocation());
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Explosion_Particles, GetActorLocation());
	Destroy();
}

