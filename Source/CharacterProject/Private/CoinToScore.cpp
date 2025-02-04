// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinToScore.h"


// Sets default values
ACoinToScore::ACoinToScore()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
//////////////////////////////////////////////////////////////////////////////////////////////

// Called when the game starts or when spawned
void ACoinToScore::BeginPlay()
{
	Super::BeginPlay();
	
}

//////////////////////////////////////////////////////////////////////////////////////////////

void ACoinToScore::PickUp(ACasurus* Character)
{
	
	UDropperGameInstance* DropperInstance = GetGameInstance<UDropperGameInstance>();
	if (DropperInstance)
	{
		DropperInstance->AddCoins(CoinValue);
		Destroy();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No Game Instance found"));
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////

// Called every frame
void ACoinToScore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

