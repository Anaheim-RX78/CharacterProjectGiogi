// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "Engine/DataAsset.h"
#include "AbilityData.generated.h"

/**
 * 
 */
UCLASS()
class CHARACTERPROJECT_API UAbilityData : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	FString PrettyName;

	UPROPERTY(EditAnywhere)
	FString Description;

	UPROPERTY(EditAnywhere)
	UTexture2D* Image;

	UPROPERTY(EditAnywhere, Category = Item)
	TSubclassOf<AAbility> Ability;

	
	
};
