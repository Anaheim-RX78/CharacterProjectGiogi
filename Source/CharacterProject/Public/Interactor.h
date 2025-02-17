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

	// Set the max Distance for the interaction range
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interactor)
	float InteractionDistance = 1000.0f;

	// Set The Interaction Profile
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interactor)
	FName InteractionProfile = "Interaction";

	// Set The collision Channel On which the trace response
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interactor)
	TEnumAsByte<ECollisionChannel> InteractionChannel;

	// Create The Variable for The Current Interactable
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Interactor)
	UInteractable* CurrentInteractable = nullptr;
	
	// Called when the game starts
	virtual void BeginPlay() override;

	// Called in the Tick check for any Interactable Components
	UFUNCTION(BlueprintCallable, Category = Interactor)
	void CheckInteractionRange();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Call The Interact Function inside the Interactable
	UFUNCTION(BlueprintCallable, Category = Interactor)
	void Interact();
		
};
