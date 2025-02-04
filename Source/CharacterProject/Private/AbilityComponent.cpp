// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityComponent.h"

#include "GameFramework/Character.h"


// Sets default values for this component's properties
UAbilityComponent::UAbilityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAbilityComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAbilityComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

// Set The First Slot
void UAbilityComponent::SetFirstSlot(UAbilityData* Ability)
{
	if (Ability != nullptr)
	{
		FirstSlot = Ability;
		CallOnChanges();
	}
}

// Set The Second Slot
void UAbilityComponent::SetSecondSlot(UAbilityData* Ability)
{
	if (Ability != nullptr)
	{
		SecondSlot = Ability;
		CallOnChanges();
	}
}

// Get A Random Ability And Then If A Slot is Empty Add to It
void UAbilityComponent::AddRandomAbility()
{
	UAbilityData* Ability = GetRandomAbility();
	
	if (!FirstSlot)
	{
		SetFirstSlot(Ability);
		UGameplayStatics::PlaySound2D(GetWorld(), ObtainedAbilitySound);
		return;
	}

	if (!SecondSlot)
	{
		SetSecondSlot(Ability);
		UGameplayStatics::PlaySound2D(GetWorld(), ObtainedAbilitySound);
		return;
	}

	UGameplayStatics::PlaySound2D(GetWorld(), AbilityFullSound);
}

// Return A Random AbilityData
UAbilityData* UAbilityComponent::GetRandomAbility()
{
	if (Abilities.Num() != 0)
	{
		int Index = UKismetMathLibrary::RandomIntegerInRange(0, Abilities.Num() - 1);
		return Abilities[Index];
	}

	return nullptr;
}

void UAbilityComponent::CallOnChanges()
{
	// If The First & Second Slot Are Valid Then Call OnAbilitiesChange Event With Both Slots Info
	if (FirstSlot != nullptr && SecondSlot != nullptr)
	{
		FString FirstPrettyName = FirstSlot->PrettyName;
		FString FirstDescription = FirstSlot->Description;
		UTexture2D* FirstImage = FirstSlot->Image;
		TSubclassOf<AAbility> FirstAbility = FirstSlot->Ability;
	
		FString SecondPrettyName = SecondSlot->PrettyName;
		FString SecondDescription = SecondSlot->Description;
		UTexture2D* SecondImage = SecondSlot->Image;
		TSubclassOf<AAbility> SecondAbility = SecondSlot->Ability;
		
		FAbilitySlotsPayload Payload
		{
			FirstPrettyName,
			FirstDescription,
			FirstImage,
			FirstAbility,
			SecondPrettyName,
			SecondDescription,
			SecondImage,
			SecondAbility
		};
		
		OnAbilitiesChange.Broadcast(Payload);
		
	}
	// if Only The Second SLot Is Valid Nothing is Called
	else if (FirstSlot == nullptr && SecondSlot != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Format(TEXT("SecondSlot: {0}"), {1}));

	}
	// if Only The Second Slot is Valid Call the Event With Only The Valid Info
	else if (SecondSlot == nullptr && FirstSlot != nullptr)
	{
		FString FirstPrettyName = FirstSlot->PrettyName;
		FString FirstDescription = FirstSlot->Description;
		UTexture2D* FirstImage = FirstSlot->Image;
		TSubclassOf<AAbility> FirstAbility = FirstSlot->Ability;
	
		FString SecondPrettyName = "Empty";
		FString SecondDescription = "Null";
		UTexture2D* SecondImage = EmptySlot;
		TSubclassOf<AAbility> SecondAbility = nullptr;
		
		FAbilitySlotsPayload Payload
		{
			FirstPrettyName,
			FirstDescription,
			FirstImage,
			FirstAbility,
			SecondPrettyName,
			SecondDescription,
			SecondImage,
			SecondAbility
		};
		
		OnAbilitiesChange.Broadcast(Payload);
		
	}
	// If Only The First Slot Is Valid Call The Event With Only The First Slot Info
	else
	{
		FString FirstPrettyName = "Empty";
		FString FirstDescription = "Null";
		UTexture2D* FirstImage = EmptySlot;
		TSubclassOf<AAbility> FirstAbility = nullptr;
	
		FString SecondPrettyName = "Empty";
		FString SecondDescription = "Null";
		UTexture2D* SecondImage = EmptySlot;
		TSubclassOf<AAbility> SecondAbility = nullptr;
		
		FAbilitySlotsPayload Payload
		{
			FirstPrettyName,
			FirstDescription,
			FirstImage,
			FirstAbility,
			SecondPrettyName,
			SecondDescription,
			SecondImage,
			SecondAbility
		};
		
		OnAbilitiesChange.Broadcast(Payload);
	}
}

// Swtich The Abilitiies In The Two Slots if Both of Them Are Valid
void UAbilityComponent::SwitchSlots()
{
	if (FirstSlot != nullptr && SecondSlot != nullptr)
	{
		UGameplayStatics::PlaySound2D(GetWorld(), SwitchAbilitySound);
		UAbilityData* Ability = FirstSlot;
		SetFirstSlot(SecondSlot);
		SetSecondSlot(Ability);
	}
	else
	{
		UGameplayStatics::PlaySound2D(GetWorld(), AbilityFullSound);
	}
}

// Spawn The Actor And Then Set The First Ability As The Second And Clear The Second Slot
void UAbilityComponent::UseAbility()
{
	if (FirstSlot != nullptr)
	{
		AAbility* UsedAbility = GetWorld()->SpawnActor<AAbility>(FirstSlot->Ability, FVector::ZeroVector, FRotator::ZeroRotator);
		UsedAbility->OwnerCharacter = Cast<ACharacter>(GetOwner());
		
		UGameplayStatics::PlaySound2D(GetWorld(), UseAbilitySound);
		
		FirstSlot = SecondSlot;
		SecondSlot = nullptr;
		CallOnChanges();
	}
	else
	{
		UGameplayStatics::PlaySound2D(GetWorld(), AbilityFullSound);
	}
}

