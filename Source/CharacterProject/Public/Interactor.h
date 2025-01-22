// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interactable.h"
#include "Interactor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHARACTERPROJECT_API UInteractor : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractor();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interactor)
	float InteractionDistance = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interactor)
	FName InteractionProfile = "Interaction";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interactor)
	TEnumAsByte<ECollisionChannel> InteractionChannel;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Interactor)
	UInteractable* CurrentInteractable = nullptr;
	
	// Called when the game starts
	virtual void BeginPlay() override;

	void CheckInteractionRange();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Interact();
		
};
