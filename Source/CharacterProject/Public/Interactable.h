// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItemData.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ActorComponent.h"
#include "Interactable.generated.h"

USTRUCT(BlueprintType)
struct FInteractorPayload
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	AActor* Interactor;

	UPROPERTY(BlueprintReadOnly)
	FVector Location;
	
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractorHandler, FInteractorPayload, Payload);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHARACTERPROJECT_API UInteractable : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractable();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interaction)
	FString  InteractionName;

	UPROPERTY(EditAnywhere, Category = Sound)
	USoundBase* InteractionSound;
	
	// Called when the game starts
	virtual void BeginPlay() override;

public:

	UPROPERTY(BlueprintAssignable)
	FOnInteractorHandler OnInteract;
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	virtual void Interact(FInteractorPayload Payload);

	UFUNCTION(BlueprintCallable)
	FString GetInteractionName() const;
	
};
