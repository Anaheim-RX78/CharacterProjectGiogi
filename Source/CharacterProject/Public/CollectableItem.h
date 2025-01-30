// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CollectableSpawner.h"
#include "GameFramework/Actor.h"
#include "DropperGameInstance.h"
#include "Pinko.h"
#include "Components/CapsuleComponent.h"
#include "CollectableItem.generated.h"

UCLASS()
class CHARACTERPROJECT_API ACollectableItem : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UCapsuleComponent* capsule;
	
public:
	
	// Sets default values for this actor's properties
	ACollectableItem();

protected:

	UPROPERTY(EditAnywhere, Category = Sound)
	USoundBase* PickUpSound;

	UPROPERTY();
	ACollectableSpawner* MySpawner;

	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable)
	virtual void PickUp(APinko* Character);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetSpawner(ACollectableSpawner* Spawner);

};
