// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaDeNaves_F.h"

// Sets default values
AFabricaDeNaves_F::AFabricaDeNaves_F()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

ANaveEnemiga* AFabricaDeNaves_F::Get_Nave(FString Identificador)
{
	ANaveEnemiga* Squadron = Crear_Squadron(Identificador);
	return Squadron;
}

// Called when the game starts or when spawned
void AFabricaDeNaves_F::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFabricaDeNaves_F::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

