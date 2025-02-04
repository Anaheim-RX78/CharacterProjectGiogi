// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "AbilityData.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/ActorComponent.h"
#include "AbilityComponent.generated.h"

USTRUCT(BlueprintType)
struct FAbilitySlotsPayload
{
	GENERATED_BODY()

// The Info Of The First Slot For The UI
	
	UPROPERTY(BlueprintReadOnly)
	FString FirstPrettyName;

	UPROPERTY(BlueprintReadOnly)
	FString FirstDescription;

	UPROPERTY(BlueprintReadOnly)
	UTexture2D* FirstImage;

	UPROPERTY(BlueprintReadOnly, Category = Item)
	TSubclassOf<AAbility> FirstAbility;


// The Info of The Second Slot for The UI

	UPROPERTY(BlueprintReadOnly)
	FString SecondPrettyName;

	UPROPERTY(BlueprintReadOnly)
	FString SecondDescription;

	UPROPERTY(BlueprintReadOnly)
	UTexture2D* SecondImage;

	UPROPERTY(BlueprintReadOnly, Category = Item)
	TSubclassOf<AAbility> SecondAbility;
	
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilitiesChangeHandler, FAbilitySlotsPayload, Payload);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHARACTERPROJECT_API UAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAbilityComponent();

protected:

#pragma region Sounds
	
	UPROPERTY(EditAnywhere, Category = Sound)
	USoundBase* ObtainedAbilitySound;

	UPROPERTY(EditAnywhere, Category = Sound)
	USoundBase* SwitchAbilitySound;

	UPROPERTY(EditAnywhere, Category = Sound)
	USoundBase* UseAbilitySound;

	UPROPERTY(EditAnywhere, Category = Sound)
	USoundBase* AbilityFullSound;

#pragma endregion
	
	UPROPERTY(EditAnywhere, Category = Settings)
	UTexture2D* EmptySlot;
	

	// the Array Of Possible Random Abilities
	UPROPERTY(EditAnywhere, Category = "Ability")
	TArray<UAbilityData*> Abilities;

	// Create The First Slot for the abilities
	UPROPERTY(VisibleAnywhere, Category = "Ability")
	UAbilityData* FirstSlot = nullptr;

	// Create The Second Slot
	UPROPERTY(VisibleAnywhere, Category = "Ability")
	UAbilityData* SecondSlot = nullptr;


	// Return A Random Ability In The Range Of The Possible Abilities Array
	UFUNCTION(BlueprintCallable, Category = "Ability")
	UAbilityData* GetRandomAbility();

	// Call this Function Whenever The Slots Changes Anything. Is Needed For The Widget UI
	UFUNCTION(BlueprintCallable, Category = "Ability")
	void CallOnChanges();
	
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Calls An Event On Changes
	UPROPERTY(BlueprintAssignable)
	FOnAbilitiesChangeHandler OnAbilitiesChange;

	// Set The First Slot With A Valid Ability
	UFUNCTION(BlueprintCallable, Category = "Ability")
	void SetFirstSlot(UAbilityData* Ability);

	// Set The Second Slot With A Valid Ability
	UFUNCTION(BlueprintCallable, Category = "Ability")
	void SetSecondSlot(UAbilityData* Ability);

	// Get A Random Ability And Add It in A Avaible Slot
	UFUNCTION(BlueprintCallable, Category = "Ability")
	void AddRandomAbility();

	// Switch the First And Second Slot In Viable
	UFUNCTION(BlueprintCallable, Category = "Ability")
	void SwitchSlots();

	// If The First Slot Is Valid Use The First Ability
	UFUNCTION(BlueprintCallable, Category = "Ability")
	void UseAbility();
		
};
