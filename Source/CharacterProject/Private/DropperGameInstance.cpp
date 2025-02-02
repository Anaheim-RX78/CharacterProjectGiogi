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
		if (Attempts.Contains(LevelIdentifier))
		{
			CurrentAttempts = Attempts[LevelIdentifier];
		}else
		{
			CurrentAttempts = 0;
		}

		if (MaxDepth.Contains(LevelIdentifier))
		{
			CurrentMaxDepth = Attempts[LevelIdentifier];
		}else
		{
			CurrentMaxDepth = 0;
		}

		if (StarScores.Contains(LevelIdentifier))
		{
			CurrentStarScore = StarScores[LevelIdentifier];
		}else
		{
			CurrentStarScore = 0;
		}
		SpawnLocation = FVector::ZeroVector;
	}
}
#pragma endregion
#pragma region ScoreSaveFunctions
// Save every Current Score Info with The reference of the Level
void UDropperGameInstance::SaveScore(FString LevelIdentifier)
{
	if (Attempts.Contains(LevelIdentifier))
	{
		Attempts[LevelIdentifier] = CurrentAttempts; // Update existing value
	}
	else
	{
		Attempts.Add(LevelIdentifier, CurrentAttempts); // Add a new entry
	}

	if (MaxDepth.Contains(LevelIdentifier))
	{
		MaxDepth[LevelIdentifier] = CurrentMaxDepth;
	}
	else
	{
		MaxDepth.Add(LevelIdentifier, CurrentMaxDepth);
	}

	if (StarScores.Contains(LevelIdentifier))
	{
		StarScores[LevelIdentifier] = CurrentStarScore;
	}
	else
	{
		StarScores.Add(LevelIdentifier, CurrentStarScore);
	}
}
#pragma endregion

void UDropperGameInstance::AddCoins(int Amount)
{
	CoinScore = CoinScore + Amount;
	if (CoinScore >= 100)
	{
		CoinScore = (100 - CoinScore) * -1;
		OnMaxCoinReached();
	}
	OnCoinAdded.Broadcast(CoinScore);
}

void UDropperGameInstance::AddStars(int Amount)
{
	CurrentStarScore = CurrentStarScore + Amount;
	OnStarsAdded.Broadcast(CurrentStarScore);
}
