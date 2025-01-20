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

	UPROPERTY(EditAnywhere, Category = Item)
	int Amount;

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
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AddItem(AInventoryItemActor* Item, int Amount);

	void AddItem(UInventoryItemData* Item, int Amount);

	void DropItem(UInventoryItemData* Item, int Amount, FVector Location);

	void DropItem(int Index, int Amount, FVector Location);

	UPROPERTY(EditAnywhere, Category = Item)
	TArray<FInventorySlot> Items;

	FInventorySlot* GetSlotByData(UInventoryItemData* Item);
		
};
