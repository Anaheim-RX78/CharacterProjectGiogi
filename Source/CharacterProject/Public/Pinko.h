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

protected:
	
	UPROPERTY(VisibleAnywhere)
	int ItemIndex;

	UPROPERTY(EditAnywhere, Category = Ability)
	UAbilityComponent* Abilities;

	
	UPROPERTY(VisibleAnywhere)
	bool isDead;
	
	
	UPROPERTY(EditAnywhere, Category = "Movement")
	float WalkSpeed = 400.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float RunSpeed = 800.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MovementSpeedMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float JumpForce = 1000.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	bool PrevFallingState;


	
	UPROPERTY(EditAnywhere, Category = "Camera")
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Camera")
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, Category = "Interact")
	UInteractor* Interactor;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	
	UPROPERTY(EditAnywhere, Category = "Inventory")
	UInventory* Inventory;

	UInteractor* GetInteractorComponent() const { return Interactor; }
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void DisplayCoins();

	
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
	void CheckIsDead();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

