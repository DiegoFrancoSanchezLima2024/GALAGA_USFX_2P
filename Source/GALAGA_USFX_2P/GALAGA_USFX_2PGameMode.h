// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GALAGA_USFX_2PGameMode.generated.h"

class AFabricaDeNaves_1_F;

UCLASS(minimalapi)
class AGALAGA_USFX_2PGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    AGALAGA_USFX_2PGameMode();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

private:
    AFabricaDeNaves_1_F* FabricaNaves;

    float Tiempo1;
    float Tiempo2;
};