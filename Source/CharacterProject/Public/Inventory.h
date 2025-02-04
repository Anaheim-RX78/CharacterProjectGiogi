// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItemData.h"
#include "Components/ActorComponent.h"
#include "Inventory.generated.h"

USTRUCT()
struct FInventorySlot
{
	GENERATED_BODY()

	// int the amount of The items
	UPROPERTY(EditAnywhere, Category = Item)
	int Amount;

	// the reference of the item data
	UPROPERTY(EditAnywhere, Category = Item)
	UInventoryItemData* ItemData;
	
};

UCLASS( ClassGroup=(InventorySystem), meta=(BlueprintSpawnableComponent) )
class CHARACTERPROJECT_API UInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventory();

protected:
	
	// Called when the game starts
	virtual void BeginPlay() override;

public:

	// Set the array of the Items Slots
	UPROPERTY(EditAnywhere, Category = Item)
	TArray<FInventorySlot> Items;

	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Call The Add Item giving the Item Data of the Actor with an Amount
	void AddItem(AInventoryItemActor* Item, int Amount);

	// Add to The inventory the item Data with an amount
	void AddItem(UInventoryItemData* Item, int Amount);

	// Spawn The Amount of actors at the location
	void DropItem(UInventoryItemData* Item, int Amount, FVector Location);

	// Remove the amount of one item data by the index and if < of 0 remove it from the Array
	void DropItem(int Index, int Amount, FVector Location, bool SpawnActor);

	// Return The Slot of an ItemData
	FInventorySlot* GetSlotByData(UInventoryItemData* Item);
		
};
