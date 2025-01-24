// Fill out your copyright notice in the Description page of Project Settings.


#include "DropperGameInstance.h"

#pragma region LevelFunctions
// Check if the opened level is the same as the one requested then refresh the current score info
void UDropperGameInstance::OnLevelLoaded(FString LevelIdentifier)
{
	if (LevelIdentifier == CurrentLevelIdentifier)
	{
		// if the same level is opened then ++ on Attemps and we save every current score in the Level score infos
		CurrentAttempts ++;
		SaveScore(LevelIdentifier);
	}
	else
	{
		// if a new level is opened refresh every current Score Info
		CurrentAttempts = 0;
		CurrentMaxDepth = 0;
		CurrentCoinScore = 0;
		CurrentStarScore = 0;
	}
}
#pragma endregion
#pragma region ScoreSaveFunctions
// Save every Current Score Info with The reference of the Level
void UDropperGameInstance::SaveScore(FString LevelIdentifier)
{
	Attempts[LevelIdentifier] = CurrentAttempts;
	MaxDepth[LevelIdentifier] = CurrentMaxDepth;
	CoinScores[LevelIdentifier] = CurrentCoinScore;
	StarScores[LevelIdentifier] = CurrentStarScore;
}
#pragma endregion