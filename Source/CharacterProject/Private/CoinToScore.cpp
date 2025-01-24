// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinToScore.h"

#include "Pinko.h"

void ACoinToScore::OnInteract(FInteractorPayload Payload)
{
	
	UDropperGameInstance* DropperInstance = GetGameInstance<UDropperGameInstance>();
	if (DropperInstance)
	{
		UInventory* Inventory = Cast<APinko>(Payload.Interactor)->Inventory;
		Inventory->AddItem(this, CoinValue);
		DropperInstance->CurrentCoinScore = DropperInstance->CurrentCoinScore + CoinValue;
		Cast<APinko>(Payload.Interactor)->DisplayCoins();
		Destroy();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No Game Instance found"));
	}
}

// Sets default values
ACoinToScore::ACoinToScore()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	capsule = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	capsule->SetupAttachment(GetRootComponent());

	interactable = CreateDefaultSubobject<UInteractable>("Interactable");

	interactable->OnInteract.AddDynamic(this, &ACoinToScore::OnInteract);

}
//////////////////////////////////////////////////////////////////////////////////////////////

// Called when the game starts or when spawned
void ACoinToScore::BeginPlay()
{
	Super::BeginPlay();
	
}

//////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////

// Called every frame
void ACoinToScore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

