// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.h"
#include "FabricaDeNaves_F.generated.h"

UCLASS()
class GALAGA_USFX_2P_API AFabricaDeNaves_F : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFabricaDeNaves_F();

public:

	ANaveEnemiga* Get_Nave(FString Identificador);

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	//METODO QUE NOS AYUDA A OBTENER LOS IDENTIFICADORES DE LAS NAVES PARA LUEGO LLEGAR A CREALAS A CADA UNO DE ESTAS
	virtual ANaveEnemiga* Crear_Squadron(FString Nave_Identificador) PURE_VIRTUAL(AFabricaDeNaves_F::Crear_Squadron, return nullptr;);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};