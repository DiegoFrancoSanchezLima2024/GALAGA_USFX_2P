// Fill out your copyright notice in the Description page of Project Settings.

#include "FabricaDeNaves_1_F.h"
#include "NaveEnemigaAbastecimiento.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaTransporte.h"

AFabricaDeNaves_1_F::AFabricaDeNaves_1_F()
{
	CurrentRow = 0;
	CurrentColumn = 0;
	GenerateGrid(4, 3, 400.0f, 400.0f);  // Example grid of 4 columns and 3 rows with 400 units spacing
}

void AFabricaDeNaves_1_F::GenerateGrid(int32 Columns, int32 Rows, float ColumnSpacing, float RowSpacing)
{
	FVector BaseLocation = FVector(815.769897f, -165.059402f, 214.727936f);

	for (int32 Column = 0; Column < Columns; ++Column)
	{
		for (int32 Row = 0; Row < Rows; ++Row)
		{
			FVector Location = FVector(
				BaseLocation.X + Column * ColumnSpacing,
				BaseLocation.Y + Row * RowSpacing,
				BaseLocation.Z
			);
			SpawnLocations.Add(Location);
		}
	}
}

ANaveEnemiga* AFabricaDeNaves_1_F::Crear_Squadron(FString Nave_Identificador)
{
	if (CurrentColumn * 3 + CurrentRow >= SpawnLocations.Num())
	{
		UE_LOG(LogTemp, Warning, TEXT("No more spawn locations available."));
		return nullptr;
	}

	FVector SpawnLocation = SpawnLocations[CurrentColumn * 3 + CurrentRow];
	FRotator Rotation = FRotator(0.f, 0.f, 0.f);

	ANaveEnemiga* Nave = nullptr;

	if (Nave_Identificador.Equals("NaveEnemigaAbastecimiento"))
		Nave = GetWorld()->SpawnActor<ANaveEnemigaAbastecimiento>(ANaveEnemigaAbastecimiento::StaticClass(), SpawnLocation, Rotation);
	else if (Nave_Identificador.Equals("NaveEnemigaCaza"))
		Nave = GetWorld()->SpawnActor<ANaveEnemigaCaza>(ANaveEnemigaCaza::StaticClass(), SpawnLocation, Rotation);
	else if (Nave_Identificador.Equals("NaveEnemigaTransporte"))
		Nave = GetWorld()->SpawnActor<ANaveEnemigaTransporte>(ANaveEnemigaTransporte::StaticClass(), SpawnLocation, Rotation);

	// Update grid position for next spawn
	CurrentRow++;
	if (CurrentRow >= 3)  // assuming 3 rows
	{
		CurrentRow = 0;
		CurrentColumn++;
	}

	return Nave;
}