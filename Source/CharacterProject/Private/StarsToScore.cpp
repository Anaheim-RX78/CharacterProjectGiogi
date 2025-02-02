// Fill out your copyright notice in the Description page of Project Settings.


#include "StarsToScore.h"

// Sets default values
AStarsToScore::AStarsToScore()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
//////////////////////////////////////////////////////////////////////////////////////////////

// Called when the game starts or when spawned
void AStarsToScore::BeginPlay()
{
	Super::BeginPlay();
	
}

//////////////////////////////////////////////////////////////////////////////////////////////

void AStarsToScore::PickUp(APinko* Character)
{
	
	UDropperGameInstance* DropperInstance = GetGameInstance<UDropperGameInstance>();
	if (DropperInstance)
	{
		DropperInstance->AddStars(1);
		Destroy();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No Game Instance found"));
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////

// Called every frame
void AStarsToScore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

