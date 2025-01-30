// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ability.generated.h"

UCLASS()
class CHARACTERPROJECT_API AAbility : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAbility();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	ACharacter* OwnerCharacter;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Settings")
	class UAbilityData* AbilityData;

	
protected:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
