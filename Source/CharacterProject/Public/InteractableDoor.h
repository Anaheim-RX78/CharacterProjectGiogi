// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "InteractableDoor.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CHARACTERPROJECT_API UInteractableDoor : public UInteractable
{
	GENERATED_BODY()

protected:

	UPROPERTY()
	class ACheckPointDoor* checkPointDoor;
	
	virtual void Interact(FInteractorPayload Payload) override;
	
};
