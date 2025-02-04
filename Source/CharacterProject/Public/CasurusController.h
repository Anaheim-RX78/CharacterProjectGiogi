// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "CharacterProject/CharacterProjectCharacter.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMap.h"
#include "Casurus.h"
#include "CasurusController.generated.h"

/**
 * 
 */
UCLASS()
class CHARACTERPROJECT_API ACasurusController : public APlayerController
{
	GENERATED_BODY()

protected:

	UPROPERTY(VisibleAnywhere)
	ACasurus* Casurus;
	
	UPROPERTY(EditAnywhere, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMap* InputMap;

	virtual void SetupInputComponent() override;

	// on posses cast to Casurus and save it as a variable
	virtual void OnPossess(APawn* InPawn) override;

	UFUNCTION()
	void Move(const FInputActionValue& Value);

	UFUNCTION()
	void StartSprint(const FInputActionValue& Value);

	UFUNCTION()
	void StopSprint(const FInputActionValue& Value);

	UFUNCTION()
	void Look(const FInputActionValue& Value);

	UFUNCTION()
	void Jump(const FInputActionValue& Value);

	UFUNCTION()
	void Interact(const FInputActionValue& Value);

	UFUNCTION()
	void UseAbility(const FInputActionValue& Value);

	UFUNCTION()
	void SwitchAbility(const FInputActionValue& Value);
	
};
