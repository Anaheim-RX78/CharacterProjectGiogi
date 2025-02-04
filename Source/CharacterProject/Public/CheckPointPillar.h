// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItemData.h"
#include "Casurus.h"
#include "InteractablePillar.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "CheckPointPillar.generated.h"

UCLASS()
class CHARACTERPROJECT_API ACheckPointPillar : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACheckPointPillar();

protected:

	UPROPERTY(EditAnywhere, Category = Interactable)
	UInteractablePillar* Interactable;

	UPROPERTY(EditAnywhere, Category = Interactable)
	UBoxComponent* Box;

	UPROPERTY(VisibleAnywhere, Category = Interactable)
	UInventoryItemData* Key;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings)
	USceneComponent* CheckPoint;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;


	UPROPERTY()
	bool isOpen = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	bool CheckKey(FInteractorPayload Payload);

	UFUNCTION()
	void Interacted(FInteractorPayload Payload);

	UFUNCTION(BlueprintImplementableEvent)
	void OpenDoor();
		

};
