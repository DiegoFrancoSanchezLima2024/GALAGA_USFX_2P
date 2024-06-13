// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaCaza.h"
#include "Components/CapsuleComponent.h"
#include "Particles/ParticleSystem.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystem.h"
#include "Components/ShapeComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "Components/BoxComponent.h"
#include "GALAGA_USFX_2PPawn.h"

ANaveEnemigaCaza::ANaveEnemigaCaza()
{
	PrimaryActorTick.bCanEverTick = true;


	//|*| COMPONENTE MALLA DE LA NAVE |*|
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));
	if (MeshAsset.Succeeded())
	{
		Nave_Mesh->SetStaticMesh(MeshAsset.Object);

		// Modificar la escala del componente de malla
		FVector NewScale(1.5f, 1.5f, 1.5f); // Escala modificada
		Nave_Mesh->SetWorldScale3D(NewScale);
	}

	//|*| COMPONENTE DE PARTICULA DE LA NAVE |*|
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));

	if (ParticleAsset.Succeeded())
	{
		Explosion_Nave = Cast<UParticleSystem>(ParticleAsset.Object);
	}

	//|*| COMPONENTE DE SONIDO DE LA NAVE |*|
	static ConstructorHelpers::FObjectFinder<USoundBase> AssetExplosionSound(TEXT("SoundWave'/Game/StarterContent/Audio/Explosion02.Explosion02'"));
	if (AssetExplosionSound.Succeeded())
	{
		Sonido_Nave = Cast<USoundBase>(AssetExplosionSound.Object);
	}


	//|*| PARA AJUSTAR LOS LIMITES DE COLISION DE LA NAVE |*|
	Colision_Nave->SetBoxExtent(FVector(80.f, 80.f, 80.f));

	//|*| INICIALIZANDO LOS ATRIBUTOS DE LA NAVE |*|

	Velocity = 40.0f;
	Tiempo_Disparo = 0;
	Danio_Recibido = 40.f;
	Tiempo_Disparo_Generar = 4.f;
	Distancia_Disparo = FVector(90.f, 0.f, 0.f);

	//Asignando un nombre 
	NombreNave = "NaveEnemgaTransporte";
}

void ANaveEnemigaCaza::NotifyActorBeginOverlap(AActor* OtherActor)
{
}

void ANaveEnemigaCaza::Componente_Destruccion()
{
}

void ANaveEnemigaCaza::Recibir_Danio(float Danio)
{
}

void ANaveEnemigaCaza::Movimiento_Nave(float DeltaTime)
{
	FVector PosicionActual = GetActorLocation();

	// Dirección horizontal constante
	const FVector DireccionMovimiento = FVector(-1.0f, 0.0f, 0.0f);

	// Componente de desplazamiento horizontal basado en la velocidad
	FVector DesplazamientoHorizontal = DireccionMovimiento * Velocity * DeltaTime;

	// Componente de desplazamiento circular (zigzag)
	float Periodo = 2.0f; // Tiempo en segundos para completar una oscilación completa
	float Amplitud = 7.0f; // Amplitud de la oscilación (7 unidades como solicitado)
	float Angulo = FMath::Fmod(GetWorld()->TimeSeconds / Periodo, 1.0f) * 2.0f * PI;
	FVector DesplazamientoCircular = FVector(0.0f, FMath::Sin(Angulo) * Amplitud, 0.0f); // Solo en Y para zigzag horizontal

	// Calcular nueva posición combinando movimientos horizontal y circular
	FVector NuevaPosicion = PosicionActual + DesplazamientoHorizontal + DesplazamientoCircular;
	SetActorLocation(NuevaPosicion);

	// Restablece la posición si la nave cruza el límite en X
	if (NuevaPosicion.X < -1700.f)
	{
		SetActorLocation(FVector(1000.f, NuevaPosicion.Y, NuevaPosicion.Z));
	}
}

void ANaveEnemigaCaza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Movimiento_Nave(DeltaTime);
}

void ANaveEnemigaCaza::BeginPlay()
{
	Super::BeginPlay();
}
