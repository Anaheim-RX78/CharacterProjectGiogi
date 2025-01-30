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
	
	UGameInstance* Istance = UGameplayStatics::GetGameInstance(GetWorld());
	UDropperGameInstance* DropperInstance = Cast<UDropperGameInstance>(Istance);

	if (DropperInstance)
	{
		DropperInstance->CurrentMaxDepth = FMath::RandRange(0.0f, 1000.0f);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No Game Instance found"));
	}
	
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

	Inventory->DropItem(ItemIndex, 1, GetActorLocation());
}

void APinko::Interact()
{
	Interactor->Interact();
}

void APinko::useAbility()
{
	Abilities->UseAbility();
}

void APinko::SwitchAbility()
{
	Abilities->SwitchSlots();
}

#pragma endregion
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void APinko::DisplayCoins()
{
	if (UDropperGameInstance* DropperInstance = GetGameInstance<UDropperGameInstance>())
	{
		int TotalCoins = DropperInstance->CoinScore;
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Format(TEXT("Total Coins: {0}"), {TotalCoins}));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No Game Instance found"));
	}
}


void APinko::CheckIsDead()
{
	if (PrevFallingState == true)
	{
		FHitResult HitResult;

		Die();

		UGameplayStatics::PlaySound2D(GetWorld(), SplatSound);
		// try to cast to a safe land actor, if failed call Die Function
		/*
 		if (!Cast<void>(HitResult.GetActor()))
		{
			Die();
		}
		*/
	}
}

void APinko::Die()
{
	isDead = true;
	OnDeath();
}