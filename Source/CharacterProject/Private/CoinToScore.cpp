// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinToScore.h"

#include "Pinko.h"

// Sets default values
ACoinToScore::ACoinToScore()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	capsule = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	capsule->SetupAttachment(GetRootComponent());
	capsule->OnComponentBeginOverlap.AddDynamic(this, &ACoinToScore::OnOverlapped);

}
//////////////////////////////////////////////////////////////////////////////////////////////

// Called when the game starts or when spawned
void ACoinToScore::BeginPlay()
{
	Super::BeginPlay();
	
}

//////////////////////////////////////////////////////////////////////////////////////////////

void ACoinToScore::OnOverlapped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UDropperGameInstance* DropperInstance = GetGameInstance<UDropperGameInstance>();
	if (DropperInstance)
	{
		DropperInstance->CoinScore = DropperInstance->CoinScore + CoinValue;
		Cast<APinko>(OtherActor)->DisplayCoins();
		Destroy();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No Game Instance found"));
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////

// Called every frame
void ACoinToScore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

