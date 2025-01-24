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
	TArray<AAbility*> Abilities;

	UPROPERTY(VisibleAnywhere, Category = "Ability")
	AAbility* FirstSlot;

	UPROPERTY(VisibleAnywhere, Category = "Ability")
	AAbility* SecondSlot;


	UFUNCTION(BlueprintCallable, Category = "Ability")
	AAbility* GetRandomAbility();
	
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void SetFirstSlot(AAbility* Ability);

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void SetSecondSlot(AAbility* Ability);

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void AddRandomAbility();

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void SwitchSlots();

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void UseAbility();
		
};
