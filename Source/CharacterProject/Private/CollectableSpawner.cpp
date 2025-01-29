// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectableSpawner.h"

// Sets default values
ACollectableSpawner::ACollectableSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	billboard = CreateDefaultSubobject<UBillboardComponent>("Billboard");
	RootComponent = billboard;

}

// Called when the game starts or when spawned
void ACollectableSpawner::BeginPlay()
{
	Super::BeginPlay();

	SpawnActor();
	
}

// Called every frame
void ACollectableSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACollectableSpawner::SpawnActor()
{
	if (!SpawnedActor)
	{
		SpawnedActor = GetWorld()->SpawnActor<AActor>(SpawnedActorClass, GetActorLocation(), FRotator::ZeroRotator);
	}
}

