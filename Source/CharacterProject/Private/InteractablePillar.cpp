// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractablePillar.h"
#include "CheckPointPillar.h"

void UInteractablePillar::Interact(FInteractorPayload Payload)
{
	checkPointDoor = Cast<ACheckPointPillar>(GetOwner());
	checkPointDoor->Interacted(Payload);

	UGameplayStatics::PlaySound2D(GetWorld(), InteractionSound);
	
}
