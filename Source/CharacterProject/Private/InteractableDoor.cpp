// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableDoor.h"
#include "CheckPointDoor.h"

void UInteractableDoor::Interact(FInteractorPayload Payload)
{
	checkPointDoor = Cast<ACheckPointDoor>(GetOwner());
	checkPointDoor->Interacted(Payload);

	UGameplayStatics::PlaySound2D(GetWorld(), InteractionSound);
	
}
