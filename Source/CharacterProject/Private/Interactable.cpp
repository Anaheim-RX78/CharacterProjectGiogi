// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable.h"

#include "Inventory.h"
#include "InventoryItemActor.h"


// Sets default values for this component's properties
UInteractable::UInteractable()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteractable::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInteractable::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

// Call The OnInteract Event and if The Interactor Owner has An Inventory Add itSelf in it
void UInteractable::Interact(FInteractorPayload Payload)
{
	UGameplayStatics::PlaySound2D(GetWorld(), InteractionSound);
	OnInteract.Broadcast(Payload);
	if (Payload.Interactor)
	{
		if (UInventory* InteractorInventory = Payload.Interactor->FindComponentByClass<UInventory>())
		{
			InteractorInventory->AddItem(Cast<AInventoryItemActor>(GetOwner())->ItemData, 1);
		}
	}
}

// return The Name Of the Interaction
FString UInteractable::GetInteractionName() const
{
	return InteractionName;
}

