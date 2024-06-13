// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.generated.h"

UCLASS()
class GALAGA_USFX_2P_API ANaveEnemiga : public AActor
{
	GENERATED_BODY()
	
public:

    // Sets default values for this actor's properties
    ANaveEnemiga();

public:

    // ~~ Componente raiz que controlara los demas componentes ~~ 
    UPROPERTY(EditAnywhere, Category = "Componentes")
    class USceneComponent* Scena;

    // ~~ Conponente de Malla para la nave ~~
    UPROPERTY(EditAnywhere, Category = "Componentes")
    class UStaticMeshComponent* Nave_Mesh;

    // ~~ Componente de Explosion ~~
    UPROPERTY(EditAnywhere, Category = "Componentes")
    class UParticleSystem* Explosion_Nave;

    // ~~ Componente de Colsion : tipo caja ~~
    UPROPERTY(EditAnywhere, Category = "Componentes")
    class UBoxComponent* Colision_Nave;

    // ~~ Componente de Sonido ~~
    UPROPERTY(EditAnywhere, Category = "Componentes")
    class USoundBase* Sonido_Nave;

protected:

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:

    FString NombreNave;
    float Velocity;
    float Resistencia;
    float Tiempo_Disparo;
    float Tiempo_Disparo_Generar;
    FVector Distancia_Disparo;
    float Danio_Recibido;
    float Danio_Disparo;
    float Life;
    float Tiempo_M;


    float Distancia_D_CB;

    virtual void NotifyActorBeginOverlap(AActor* OtherActor);

    virtual void Componente_Destruccion();

    virtual void Recibir_Danio(float Danio);

    virtual void Disparo_Nave(float DeltaTime);

    virtual void Movimiento_Nave(float DeltaTime);

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

};
