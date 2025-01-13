// Fill out your copyright notice in the Description page of Project Settings.


#include "PallinoController.h"


void APallinoController::SetupInputComponent()
{
	Super::SetupInputComponent();

	ULocalPlayer* LocalPlayer = (ULocalPlayer*)GetLocalPlayer();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();

	Subsystem->ClearAllMappings();

	Subsystem->AddMappingContext(DefaultMappingContext, 0);

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &APallinoController::Jump);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APallinoController::Move);

	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APallinoController::Look);

	EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Started, this, &APallinoController::StartSprint);

	EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &APallinoController::StopSprint);
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
