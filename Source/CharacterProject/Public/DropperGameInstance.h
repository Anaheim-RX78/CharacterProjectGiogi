// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DropperGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CHARACTERPROJECT_API UDropperGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = Score)
	int CoinScore = 0;
	
	UPROPERTY(EditAnywhere, Category = Score)
	float MaxDepth = 0;

	UPROPERTY(EditAnywhere, Category = Score)
	int Attempts = 0;

	UPROPERTY(EditAnywhere, Category = Level)
	FString CurrentLevelIdentifier = "Level_01";

public:

	UFUNCTION(BlueprintCallable)
	void OnLevelLoaded(FString LevelIdentifier);
	
};

