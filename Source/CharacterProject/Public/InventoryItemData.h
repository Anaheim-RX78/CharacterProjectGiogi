// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InventoryItemData.generated.h"



class AInventoryItemActor;


UCLASS()
class CHARACTERPROJECT_API UInventoryItemData : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = Item)
	FString PrettyName;

	UPROPERTY(EditAnywhere, Category = Item)
	FString Description;

	UPROPERTY(EditAnywhere, Category = Item)
	float Weight;
	
	UPROPERTY(EditAnywhere, Category = Item)
	TSubclassOf<AInventoryItemActor> Item;
	
};
