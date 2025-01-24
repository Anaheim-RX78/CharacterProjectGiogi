// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/ActorComponent.h"
#include "AbilityComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHARACTERPROJECT_API UAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAbilityComponent();

protected:

	UPROPERTY(EditAnywhere, Category = "Ability")
	TArray<UAbilityData*> Abilities;

	UPROPERTY(VisibleAnywhere, Category = "Ability")
	UAbilityData* FirstSlot = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Ability")
	UAbilityData* SecondSlot = nullptr;


	UFUNCTION(BlueprintCallable, Category = "Ability")
	UAbilityData* GetRandomAbility();
	
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void SetFirstSlot(UAbilityData* Ability);

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void SetSecondSlot(UAbilityData* Ability);

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void AddRandomAbility();

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void SwitchSlots();

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void UseAbility();
		
};
