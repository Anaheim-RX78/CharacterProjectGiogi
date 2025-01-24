// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityComponent.h"

#include "AbilityData.h"
#include "Pinko.h"


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

void UAbilityComponent::SetFirstSlot(UAbilityData* Ability)
{
	if (Ability != nullptr)
	{
		FirstSlot = Ability;
	}
}

void UAbilityComponent::SetSecondSlot(UAbilityData* Ability)
{
	if (Ability != nullptr)
	{
		SecondSlot = Ability;
	}
}

void UAbilityComponent::AddRandomAbility()
{
	UAbilityData* Ability = GetRandomAbility();
	
	if (!FirstSlot)
	{
		SetFirstSlot(Ability);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Format(TEXT("FirstSlot: {0}"), {Ability->GetName()}));
	}
	else if (!SecondSlot)
	{
		SetSecondSlot(Ability);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Format(TEXT("SecondSlot: {0}"), {Ability->GetName()}));

	}
}

UAbilityData* UAbilityComponent::GetRandomAbility()
{
	if (Abilities.Num() != 0)
	{
		int Index = UKismetMathLibrary::RandomIntegerInRange(0, Abilities.Num() - 1);
		return Abilities[Index];
	}

	return nullptr;
}

void UAbilityComponent::SwitchSlots()
{
	if (FirstSlot != nullptr && SecondSlot != nullptr)
	{
		UAbilityData* Ability = FirstSlot;
		FirstSlot = SecondSlot;
		SecondSlot = Ability;
	}
}

void UAbilityComponent::UseAbility()
{
	//GetWorld()->SpawnActor<AAbility>(FirstSlot->Ability, FVector<> = 0, FRotator::ZeroRotator)->OwnerCharacter = GetOwner();
	SwitchSlots();
	SecondSlot = nullptr;
}

