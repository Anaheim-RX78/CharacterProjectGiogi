// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BillboardComponent.h"
#include "CollectableSpawner.generated.h"

UCLASS()
class CHARACTERPROJECT_API ACollectableSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollectableSpawner();

protected:

	UPROPERTY(EditAnywhere)
	UBillboardComponent* billboard;

	// The Reference of the Actor that is Spawned
	UPROPERTY()
	AActor* SpawnedActor;

	// The Class of The Actor To Spawn
	UPROPERTY(EditAnywhere, Category = "Spawner")
	TSubclassOf<AActor> SpawnedActorClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SpawnActor();

	// Reset The Reference to Nullptr When The Actor Is Destroyed
	UFUNCTION(BlueprintCallable)
	void SetSpawnedActorNull();

};
