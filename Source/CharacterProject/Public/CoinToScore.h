// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CollectableItem.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "CoinToScore.generated.h"

UCLASS()
class CHARACTERPROJECT_API ACoinToScore : public ACollectableItem
{
	GENERATED_BODY()
	
public:
	
	// Sets default values for this actor's properties
	ACoinToScore();

protected:

	UPROPERTY(EditAnywhere, Category = Settings)
	int CoinValue = 1;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PickUp(ACasurus* Character) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
