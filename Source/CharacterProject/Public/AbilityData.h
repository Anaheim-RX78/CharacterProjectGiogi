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

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString PrettyName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* Image;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Ability)
	TSubclassOf<AAbility> Ability;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Ability)
	float Duration;

	
	
};
