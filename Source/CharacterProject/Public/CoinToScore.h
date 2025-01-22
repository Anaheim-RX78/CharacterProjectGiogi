// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DropperGameInstance.h"
#include "Interactable.h"
#include "InventoryItemActor.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "CoinToScore.generated.h"

UCLASS()
class CHARACTERPROJECT_API ACoinToScore : public AInventoryItemActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UCapsuleComponent* capsule;

	UPROPERTY(EditAnywhere)
	UInteractable* interactable;
	
public:
	UFUNCTION()
	void OnInteract(FInteractorPayload Payload);
	
	// Sets default values for this actor's properties
	ACoinToScore();

protected:

	UPROPERTY(EditAnywhere, Category = Settings)
	int CoinValue;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
