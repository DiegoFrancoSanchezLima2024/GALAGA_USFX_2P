#include "GALAGA_USFX_2PGameMode.h"
#include "GALAGA_USFX_2PPawn.h"
#include "FabricaDeNaves_1_F.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

AGALAGA_USFX_2PGameMode::AGALAGA_USFX_2PGameMode()
{
    DefaultPawnClass = AGALAGA_USFX_2PPawn::StaticClass();
    Tiempo1 = 5.0f;
    Tiempo2 = 0.0f;
}

void AGALAGA_USFX_2PGameMode::BeginPlay()
{
    Super::BeginPlay();

    FabricaNaves = GetWorld()->SpawnActor<AFabricaDeNaves_1_F>(AFabricaDeNaves_1_F::StaticClass());
    if (FabricaNaves)
    {
        // Spawnea 2 naves de caza
        for (int32 i = 0; i < 2; ++i)
        {
            FabricaNaves->Crear_Squadron("NaveEnemigaTransporte");
        }

        // Spawnea 6 naves de transporte
        for (int32 i = 0; i < 6; ++i)
        {
            FabricaNaves->Crear_Squadron("NaveEnemigaCaza");
        }

        // Spawnea 4 naves de abastecimiento
        for (int32 i = 0; i < 4; ++i)
        {
            FabricaNaves->Crear_Squadron("NaveEnemigaAbastecimiento");
        }
    }
}

void AGALAGA_USFX_2PGameMode::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    Tiempo2 += DeltaTime;
}

