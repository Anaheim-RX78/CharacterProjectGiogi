// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "InventoryItemActor.h"
#include "CheckPointKey.generated.h"

/**
 * 
 */
UCLASS()
class CHARACTERPROJECT_API ACheckPointKey : public AInventoryItemActor
{
	GENERATED_BODY()

public:

	ACheckPointKey();

protected:

	UPROPERTY(EditAnywhere, Category = Interaction)
	UInteractable* Interactable;
	
};
