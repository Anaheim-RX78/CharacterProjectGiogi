// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DropperGameInstance.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "CoinToScore.generated.h"

UCLASS()
class CHARACTERPROJECT_API ACoinToScore : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UCapsuleComponent* capsule;	
	
public:
	
	// Sets default values for this actor's properties
	ACoinToScore();

protected:

	UPROPERTY(EditAnywhere, Category = Settings)
	int CoinValue;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
