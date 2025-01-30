// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectableSpawner.h"

#include "CollectableItem.h"
#include "LuckyBlock.h"

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

		// Cast to Actor that has the spawner variable ( An Interface would be more optimized )
		if (ACollectableItem* MyItem = Cast<ACollectableItem>(SpawnedActor))
		{
			MyItem->SetSpawner(this);
		}
		else if (ALuckyBlock* MyBlock = Cast<ALuckyBlock>(SpawnedActor))
		{
			MyBlock->SetSpawner(this);
		}
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Spawned Actor"));

	}
}

void ACollectableSpawner::SetSpawnedActorNull()
{
	SpawnedActor = nullptr;
}

