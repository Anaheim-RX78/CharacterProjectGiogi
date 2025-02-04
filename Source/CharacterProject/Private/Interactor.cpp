// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactor.h"



UInteractor::UInteractor()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UInteractor::BeginPlay()
{
	Super::BeginPlay();
}

void UInteractor::CheckInteractionRange()
{
	FHitResult HitResult;

	GetWorld()->LineTraceSingleByChannel(HitResult, GetComponentLocation(), GetComponentLocation() + (GetForwardVector() * InteractionDistance), InteractionChannel);
	
	//GetWorld()->LineTraceSingleByProfile(HitResult, GetComponentLocation(), GetForwardVector() * InteractionDistance, InteractionProfile);

	AActor* HitActor = HitResult.GetActor();

	if (HitActor == nullptr)
	{
		CurrentInteractable = nullptr;
		return;
	}
	
	UInteractable* Component = HitResult.GetActor()->GetComponentByClass<UInteractable>();

	if (CurrentInteractable == nullptr && Component)
	{
		CurrentInteractable = Component;
	}
	else if (CurrentInteractable && Component && Component != CurrentInteractable)
	{
		CurrentInteractable = Component;
	}
}

void UInteractor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	CheckInteractionRange();
}

void UInteractor::Interact()
{
	if (CurrentInteractable == nullptr) return;

	CurrentInteractable->Interact(FInteractorPayload{GetOwner()});
}


