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

	UPROPERTY(BlueprintReadOnly)
	FString FirstPrettyName;

	UPROPERTY(BlueprintReadOnly)
	FString FirstDescription;

	UPROPERTY(BlueprintReadOnly)
	UTexture2D* FirstImage;

	UPROPERTY(BlueprintReadOnly, Category = Item)
	TSubclassOf<AAbility> FirstAbility;


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
	

	UPROPERTY(EditAnywhere, Category = "Ability")
	TArray<UAbilityData*> Abilities;

	UPROPERTY(VisibleAnywhere, Category = "Ability")
	UAbilityData* FirstSlot = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Ability")
	UAbilityData* SecondSlot = nullptr;


	UFUNCTION(BlueprintCallable, Category = "Ability")
	UAbilityData* GetRandomAbility();

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void CallOnChanges();
	
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(BlueprintAssignable)
	FOnAbilitiesChangeHandler OnAbilitiesChange;
	
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
