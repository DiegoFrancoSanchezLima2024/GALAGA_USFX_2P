// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_2P_API ANaveEnemigaCaza : public ANaveEnemiga
{
	GENERATED_BODY()

public:

	ANaveEnemigaCaza();

public:

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	virtual void Componente_Destruccion() override;

	virtual void Recibir_Danio(float Danio) override;

	virtual void Movimiento_Nave(float DeltaTime) override;

public:

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

};
