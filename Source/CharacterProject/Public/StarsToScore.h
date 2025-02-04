// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CollectableItem.h"
#include "StarsToScore.generated.h"

/**
 * 
 */
UCLASS()
class CHARACTERPROJECT_API AStarsToScore : public ACollectableItem
{
	GENERATED_BODY()

public:
	
	// Sets default values for this actor's properties
	AStarsToScore();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PickUp(ACasurus* Character) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};