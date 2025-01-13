// Fill out your copyright notice in the Description page of Project Settings.


#include "Pinko.h"

#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
APinko::APinko()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Arm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 500;
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
}

// Called when the game starts or when spawned
void APinko::BeginPlay()
{
	Super::BeginPlay();
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	
}

// Called every frame
void APinko::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APinko::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void APinko::JumpyDumpty()
{
	Jump();
}

void APinko::SetMovementInput(const FVector2D& MovementInput)
{
	AddMovementInput(GetActorRightVector(), MovementInput.X);
	AddMovementInput(GetActorForwardVector(), MovementInput.Y);
}

void APinko::Sprinting(bool Sprinting)
{
	if (Sprinting)
	{
		GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
	}
	else
	{
		GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	}
}

void APinko::SetLookInput(const FVector2D& LookInput)
{
	AddControllerPitchInput(LookInput.Y);
	AddControllerYawInput(LookInput.X);
}

