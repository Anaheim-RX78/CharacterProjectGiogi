// Fill out your copyright notice in the Description page of Project Settings.


#include "Pinko.h"

#include "AssetTypeActions/AssetDefinition_SoundBase.h"


#pragma region Construct

// Sets default values
APinko::APinko()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// create the spring arm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Arm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 500;
	SpringArm->bUsePawnControlRotation = true;

	// create the camera and attach it to the spring arm
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	// create the inventory component
	Inventory = CreateDefaultSubobject<UInventory>(TEXT("Inventory"));

	// create the abilities component
	Abilities = CreateDefaultSubobject<UAbilityComponent>(TEXT("Abilities"));

	// create the interactor component and attach it to the camera
	Interactor = CreateDefaultSubobject<UInteractor>(TEXT("InteractorComponent"));
	Interactor->SetupAttachment(Camera, USpringArmComponent::SocketName);
}

#pragma endregion
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
# pragma region BeginFunction

// Called when the game starts or when spawned
void APinko::BeginPlay()
{
	Super::BeginPlay();
	
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	
}

#pragma endregion
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region TickFunction

// Called every frame
void APinko::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Check if Falling and increment the falling velocity
	if (GetMovementComponent()->IsFalling() == true)
	{
		MovementSpeedMultiplier += DeltaTime / 30;
		GetMovementComponent()->Velocity.Z = GetMovementComponent()->Velocity.Z * MovementSpeedMultiplier;

		// check if the current velocity is greater than tot and if so set the falling state true
		if (GetMovementComponent()->Velocity.Z < VelocityToFallState)
		{
			PrevFallingState = true;
		}
		else
		{
			PrevFallingState = false;
		}
		
	} // check if on ground to reset the movement speed multiplier and set the falling state to false
	else if (GetMovementComponent()->IsFalling() == false)
	{
		// check if the charater fell on a safe spot otherwise die
		CheckIsDead();
		MovementSpeedMultiplier = 1.0f;
		PrevFallingState = false;
		
	}
	
}

#pragma endregion
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region InizializeInputs

// Called to bind functionality to input
void APinko::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

#pragma endregion
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region MovementFunctions

// Jumps by calling the Movement Component Jump Function
void APinko::JumpyDumpty()
{
	Jump();
}

// Move Relative to the Camera Forward and Right Vector
void APinko::SetMovementInput(const FVector2D& MovementInput)
{
	AddMovementInput(FRotationMatrix(FRotator(0, GetControlRotation().Yaw, 0)).GetUnitAxis(EAxis::Y), MovementInput.X);
	AddMovementInput(FRotationMatrix(FRotator(0, GetControlRotation().Yaw, 0)).GetUnitAxis(EAxis::X), MovementInput.Y);
}

// Sprint Changing the Walk Speed Of The Movement Component
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

// Rotate The Camera
void APinko::SetLookInput(const FVector2D& LookInput)
{
	AddControllerPitchInput(LookInput.Y);
	AddControllerYawInput(LookInput.X);
}

#pragma endregion
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region InputsFunctions

// Select Next Item in The Inventory, Not Needed for the Dropper. Lesson Exercise
inline void APinko::SelectItem(bool nextItem)
{
	if (nextItem && ItemIndex < Inventory->Items.Num() - 1)
	{
		ItemIndex++;
	}
	else if (!nextItem && ItemIndex > 0)
	{
		ItemIndex--;
	}

	Inventory->DropItem(ItemIndex, 1, GetActorLocation(), true);
}

// Interact with the interactable get from the Interactor Component
void APinko::Interact()
{
	Interactor->Interact();
}

// use the ability from the Ability Component
void APinko::useAbility()
{
	Abilities->UseAbility();
}

// Switch the Abilities in the Slots from the Ability Component
void APinko::SwitchAbility()
{
	Abilities->SwitchSlots();
}

#pragma endregion
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region LifeFunctions

// Check when on ground after falling if the land is safe otherwise die
void APinko::CheckIsDead()
{
	if (PrevFallingState == true)
	{
		ECollisionChannel ObjectType = GetCharacterMovement()->CurrentFloor.HitResult.Component->GetCollisionObjectType();

		UGameplayStatics::PlaySound2D(GetWorld(), SplatSound);
 		if (ObjectType != ECC_Destructible)
		{
			Die();
		}
	}
}

// Check if is invincible otherwise call the OnDeath() event
void APinko::Die()
{
	if (IsInvincible == false)
	{
		OnDeath();	
	}
}

#pragma endregion