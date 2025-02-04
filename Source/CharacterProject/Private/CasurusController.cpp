// Fill out your copyright notice in the Description page of Project Settings.


#include "CasurusController.h"

#include "InputMap.h"


void ACasurusController::SetupInputComponent()
{
	Super::SetupInputComponent();

	ULocalPlayer* LocalPlayer = (ULocalPlayer*)GetLocalPlayer();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();

	Subsystem->ClearAllMappings();

	// The Custom Input Map Is Not Valid Deny Any Binding
	if (!InputMap)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("CHECK IN THE CONTROLLER IF YOU SELECTED THE INPUT MAP!"));
		return;
	}

	//Set The Mapping Context From The Custom InputMap Data Asset
	Subsystem->AddMappingContext(InputMap->Context, 0);

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	
	//bind on Started jump
	EnhancedInputComponent->BindAction(InputMap->Actions["Jump"], ETriggerEvent::Started, this, &ACasurusController::Jump);
	//bind on triggered Move
	EnhancedInputComponent->BindAction(InputMap->Actions["Move"], ETriggerEvent::Triggered, this, &ACasurusController::Move);
	//bind on Triggered Look
	EnhancedInputComponent->BindAction(InputMap->Actions["Look"], ETriggerEvent::Triggered, this, &ACasurusController::Look);
	//bind on Started Sprint
	EnhancedInputComponent->BindAction(InputMap->Actions["Sprint"], ETriggerEvent::Started, this, &ACasurusController::StartSprint);
	//bind on Completed Sprint
	EnhancedInputComponent->BindAction(InputMap->Actions["Sprint"], ETriggerEvent::Completed, this, &ACasurusController::StopSprint);
	//bind on Started Interact
	EnhancedInputComponent->BindAction(InputMap->Actions["Interact"], ETriggerEvent::Started, this, &ACasurusController::Interact);
	//bind on Started UseAbility
	EnhancedInputComponent->BindAction(InputMap->Actions["UseAbility"], ETriggerEvent::Started, this, &ACasurusController::UseAbility);
	//bind on Started SwitchAbility
	EnhancedInputComponent->BindAction(InputMap->Actions["SwitchAbility"], ETriggerEvent::Started, this, &ACasurusController::SwitchAbility);
	
}

// On Posses Save Casurus Variable if valid
void ACasurusController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if (ACasurus* PinkoPawn = Cast<ACasurus>(InPawn)) { Casurus = PinkoPawn; }
}

// Call The Movement Function on Casurus
void ACasurusController::Move(const FInputActionValue& Value)
{
	Casurus->SetMovementInput(Value.Get<FVector2D>());
}

// Call The Sprint Function on Casurus
void ACasurusController::StartSprint(const FInputActionValue& Value)
{
	Casurus->Sprinting(true);
}

// Call The Sprint Function on Casurus
void ACasurusController::StopSprint(const FInputActionValue& Value)
{
	Casurus->Sprinting(false);
}

// Call The Camera Function on Casurus
void ACasurusController::Look(const FInputActionValue& Value)
{
	Casurus->SetLookInput(Value.Get<FVector2D>());
}

// Call The Jump Function on Casurus
void ACasurusController::Jump(const FInputActionValue& Value)
{
	Casurus->JumpyDumpty();
}

// Call The Interact Function on Casurus
void ACasurusController::Interact(const FInputActionValue& Value)
{
	Casurus->Interact();
}

// Call The UseAbility Function on Casurus
void ACasurusController::UseAbility(const FInputActionValue& Value)
{
	Casurus->useAbility();
}

// Call The SwitchAbility Function on Casurus
void ACasurusController::SwitchAbility(const FInputActionValue& Value)
{
	Casurus->SwitchAbility();
}

