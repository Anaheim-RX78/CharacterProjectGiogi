// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilityComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "LuckyBlock.generated.h"

UCLASS()
class CHARACTERPROJECT_API ALuckyBlock : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	USphereComponent* SphereComp;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComp;
	
public:
	
	// Sets default values for this actor's properties
	ALuckyBlock();

	

protected:

	UPROPERTY(EditAnywhere, Category = Sound)
	USoundBase* PickupSound;

	UPROPERTY();
	ACollectableSpawner* MySpawner;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;	

	UFUNCTION()
	void OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SetSpawner(ACollectableSpawner* Spawner);

};
