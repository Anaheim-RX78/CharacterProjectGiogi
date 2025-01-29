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

#pragma region ScoreCurrentInfo

// here we create the variables to maintain the current score

	UPROPERTY(EditAnywhere, Category = Score)
	int CurrentStarScore = 0;

	UPROPERTY(EditAnywhere, Category = Score)
	int CoinScore = 0;
	
	UPROPERTY(EditAnywhere, Category = Score)
	float CurrentMaxDepth = 0;

	UPROPERTY(EditAnywhere, Category = Score)
	int CurrentAttempts = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CheckPoint)
	FVector SpawnLocation;

	// The level identifier for checking if the opened level is the same
	UPROPERTY(EditAnywhere, Category = Level)
	FString CurrentLevelIdentifier = "Level_01";

#pragma endregion
#pragma region ScorePerLevelInfo

// here we create the TMaps where we save the score info with the level name reference
	
	UPROPERTY(VisibleAnywhere, Category = Score)
	TMap<FString, int> StarScores;

	UPROPERTY(VisibleAnywhere, Category = Score)
	TMap<FString, float> MaxDepth;

	UPROPERTY(VisibleAnywhere, Category = Score)
	TMap<FString, int> Attempts;

#pragma endregion

public:

	// When a new level is opened this should be called to refresh the current score infos
	UFUNCTION(BlueprintCallable)
	void OnLevelLoaded(FString LevelIdentifier);

	// Save every Current Score to the reference of the Level
	UFUNCTION(BlueprintCallable)
	void SaveScore(FString LevelIdentifier);

	UFUNCTION(BlueprintCallable)
	void AddCoins(int Amount);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMaxCoinReached();
	
};

