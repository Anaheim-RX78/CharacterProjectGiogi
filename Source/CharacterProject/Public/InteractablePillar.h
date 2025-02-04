// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "InteractablePillar.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CHARACTERPROJECT_API UInteractablePillar : public UInteractable
{
	GENERATED_BODY()

protected:

	UPROPERTY()
	class ACheckPointPillar* checkPointDoor;

	// override The Interact Function
	virtual void Interact(FInteractorPayload Payload) override;
	
};
