// Fill out your copyright notice in the Description page of Project Settings.


#include "PallinoController.h"

#include "InputMap.h"


void APallinoController::SetupInputComponent()
{
	Super::SetupInputComponent();

	ULocalPlayer* LocalPlayer = (ULocalPlayer*)GetLocalPlayer();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();

	Subsystem->ClearAllMappings();

	if (!InputMap)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("CHECK IN THE CONTROLLER IF YOU SELECTED THE INPUT MAP!"));
		return;
	}

	Subsystem->AddMappingContext(InputMap->Context, 0);

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(InputMap->Actions["Jump"], ETriggerEvent::Started, this, &APallinoController::Jump);

	EnhancedInputComponent->BindAction(InputMap->Actions["Move"], ETriggerEvent::Triggered, this, &APallinoController::Move);

	EnhancedInputComponent->BindAction(InputMap->Actions["Look"], ETriggerEvent::Triggered, this, &APallinoController::Look);

	EnhancedInputComponent->BindAction(InputMap->Actions["Sprint"], ETriggerEvent::Started, this, &APallinoController::StartSprint);

	EnhancedInputComponent->BindAction(InputMap->Actions["Sprint"], ETriggerEvent::Completed, this, &APallinoController::StopSprint);

	EnhancedInputComponent->BindAction(InputMap->Actions["SelectItem"], ETriggerEvent::Started, this, &APallinoController::SelectInput);
}

void APallinoController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if (APinko* PinkoPawn = Cast<APinko>(InPawn)) { Pinko = PinkoPawn; }
}

void APallinoController::Move(const FInputActionValue& Value)
{
	Pinko->SetMovementInput(Value.Get<FVector2D>());
}

void APallinoController::StartSprint(const FInputActionValue& Value)
{
	Pinko->Sprinting(true);
}

void APallinoController::StopSprint(const FInputActionValue& Value)
{
	Pinko->Sprinting(false);
}

void APallinoController::Look(const FInputActionValue& Value)
{
	Pinko->SetLookInput(Value.Get<FVector2D>());
}

void APallinoController::Jump(const FInputActionValue& Value)
{
	Pinko->JumpyDumpty();
}

void APallinoController::SelectInput(const FInputActionValue& Value)
{
	Pinko->SelectItem(true);
}
