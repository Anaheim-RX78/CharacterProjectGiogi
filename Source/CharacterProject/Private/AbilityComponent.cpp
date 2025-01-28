// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityComponent.h"


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
		CallOnChanges();
	}
}

void UAbilityComponent::SetSecondSlot(UAbilityData* Ability)
{
	if (Ability != nullptr)
	{
		SecondSlot = Ability;
		CallOnChanges();
	}
}

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
	else if (FirstSlot == nullptr && SecondSlot != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Format(TEXT("SecondSlot: {0}"), {1}));

	}
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

void UAbilityComponent::UseAbility()
{
	if (FirstSlot != nullptr)
	{
		//GetWorld()->SpawnActor<AAbility>(FirstSlot->Ability, FVector<> = 0, FRotator::ZeroRotator)->OwnerCharacter = GetOwner();
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

