// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FabricaDeNaves_F.h"
#include "FabricaDeNaves_1_F.generated.h"

/**
 *
 */
UCLASS()
class GALAGA_USFX_2P_API AFabricaDeNaves_1_F : public AFabricaDeNaves_F
{
	GENERATED_BODY()

public:
	AFabricaDeNaves_1_F();

	// Metodo para la creacion de las naves
	virtual ANaveEnemiga* Crear_Squadron(FString Nave_Identificador) override;

private:
	int32 CurrentRow;
	int32 CurrentColumn;
	TArray<FVector> SpawnLocations;
	void GenerateGrid(int32 Rows, int32 Columns, float RowSpacing, float ColumnSpacing);
};