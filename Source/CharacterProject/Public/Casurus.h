// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilityComponent.h"
#include "Inventory.h"
#include "GameFramework/Character.h"
#include "Interactor.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Casurus.generated.h"

UCLASS()
class CHARACTERPROJECT_API ACasurus : public ACharacter
{
	GENERATED_BODY()

public:
	
	// Sets default values for this character's properties
	ACasurus();

	UPROPERTY(EditAnywhere, Category = "Inventory")
	UInventory* Inventory;

	// movement multiplier for the Z velocity. Used also in the plane ability
	UPROPERTY(BlueprintReadWrite, Category = Movement)
	float MovementSpeedMultiplier = 1.0f;

	// if invincible does not die of landing. Used in the Ability_Invincibility
	UPROPERTY(BlueprintReadWrite, Category = Movement)
	bool IsInvincible = false;
	
protected:

	UPROPERTY(EditAnywhere, Category = Sound)
	USoundBase* SplatSound;
	
	UPROPERTY(VisibleAnywhere)
	int ItemIndex;
	
#pragma region MovementVariables
	
	// Create and set the variables for the movement
	UPROPERTY(EditAnywhere, Category = Movement)
	float VelocityToFallState = -1500.0f;
	
	UPROPERTY(EditAnywhere, Category = Movement)
	float WalkSpeed = 400.0f;

	UPROPERTY(EditAnywhere, Category = Movement)
	float RunSpeed = 800.0f;

	UPROPERTY(EditAnywhere, Category = Movement)
	float JumpForce = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
	bool PrevFallingState;

#pragma endregion
#pragma region Components	

	//Create the components for the character
	UPROPERTY(EditAnywhere, Category = "Camera")
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Camera")
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, Category = "Interact")
	UInteractor* Interactor;

	UPROPERTY(VisibleAnywhere, Category = Ability)
	UAbilityComponent* Abilities;

#pragma endregion
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UInteractor* GetInteractorComponent() const { return Interactor; }
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
#pragma region LifeFunctions

	// Check the Ground and call die if it's not safe
	UFUNCTION()
	void CheckIsDead();

	// Call the Event OnDeath if not invincible
	UFUNCTION(BlueprintCallable)
	void Die();

	// Can be implemented in the blueprint when on dead
	UFUNCTION(BlueprintImplementableEvent)
	void OnDeath();
	
#pragma endregion
#pragma region MovementFunctions

	// Call the Jump Function
	UFUNCTION()
	void JumpyDumpty();

	// Set the movement input by using the control rotation
	UFUNCTION()
	void SetMovementInput(const FVector2D& MovementInput);

	// Set the max velocity of the walk speed
	UFUNCTION()
	void Sprinting(bool Sprinting);

	// set the input for the camera
	UFUNCTION()
	void SetLookInput(const FVector2D& LookInput);

#pragma endregion

	UFUNCTION()
	void SelectItem(bool nextItem);

	UFUNCTION()
	void Interact();

	UFUNCTION()
	void useAbility();

	UFUNCTION()
	void SwitchAbility();


	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

