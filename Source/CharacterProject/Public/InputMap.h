// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EnhancedInputSubsystems.h"
#include "InputMap.generated.h"

/**
 * 
 */

UCLASS(Blueprintable)
class CHARACTERPROJECT_API UInputMap : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = input)
	UInputMappingContext* Context;

	UPROPERTY(EditAnywhere, Category = input)
	TMap<FString, UInputAction*> Actions;
	
};
