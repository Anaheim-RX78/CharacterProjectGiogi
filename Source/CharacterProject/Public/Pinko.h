// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilityComponent.h"
#include "Inventory.h"
#include "GameFramework/Character.h"
#include "DropperGameInstance.h"
#include "Interactor.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Pinko.generated.h"

UCLASS()
class CHARACTERPROJECT_API APinko : public ACharacter
{
	GENERATED_BODY()

public:
	
	// Sets default values for this character's properties
	APinko();

	UPROPERTY(EditAnywhere, Category = "Inventory")
	UInventory* Inventory;
	
protected:

	UPROPERTY(EditAnywhere, Category = Sound)
	USoundBase* SplatSound;
	
	UPROPERTY(VisibleAnywhere)
	int ItemIndex;

	
	UPROPERTY(VisibleAnywhere)
	bool isDead;
	
#pragma region MovementVariables
	
	// Create and set the variables for the movement
	UPROPERTY(EditAnywhere, Category = Settings)
	float VelocityToFallState = -1500.0f;
	
	UPROPERTY(EditAnywhere, Category = Settings)
	float WalkSpeed = 400.0f;

	UPROPERTY(EditAnywhere, Category = Settings)
	float RunSpeed = 800.0f;

	UPROPERTY(EditAnywhere, Category = Settings)
	float JumpForce = 1000.0f;

	UPROPERTY(EditAnywhere, Category = Settings)
	bool PrevFallingState;
	
	UPROPERTY()
	float MovementSpeedMultiplier = 1.0f;

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

	UFUNCTION()
	void DisplayCoins();

	UFUNCTION()
	void CheckIsDead();

	
	UFUNCTION()
	void JumpyDumpty();

	UFUNCTION()
	void SetMovementInput(const FVector2D& MovementInput);

	UFUNCTION()
	void Sprinting(bool Sprinting);

	UFUNCTION()
	void SetLookInput(const FVector2D& LookInput);
	

	UFUNCTION()
	void SelectItem(bool nextItem);

	UFUNCTION()
	void Interact();

	UFUNCTION()
	void useAbility();

	UFUNCTION()
	void SwitchAbility();

	UFUNCTION(BlueprintCallable)
	void Die();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDeath();
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

