// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckPointPillar.h"



// Sets default values
ACheckPointPillar::ACheckPointPillar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("root"));
	RootComponent = Root;
	
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("KeyHolder"));
	Box->SetupAttachment(Root);

	CheckPoint = CreateDefaultSubobject<USceneComponent>(TEXT("CheckPoint"));
	CheckPoint->SetupAttachment(Root);

	Interactable = CreateDefaultSubobject<UInteractablePillar>(TEXT("Interactable"));

}

// Called when the game starts or when spawned
void ACheckPointPillar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACheckPointPillar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ACheckPointPillar::CheckKey(FInteractorPayload Payload)
{
	if (ACasurus* Character = Cast<ACasurus>(Payload.Interactor))
	{
		if (Character->Inventory->Items.Num() > 0)
		{
			if (Character->Inventory->Items[0].Amount > 0)
			{
				Character->Inventory->DropItem(0, 1, GetActorLocation(), false);
				return true;	
			}
		}
	}
	
	return false;
	
}

void ACheckPointPillar::Interacted(FInteractorPayload Payload)
{
	if (!isOpen)
	{
		if (CheckKey(Payload))
		{
			isOpen = true;
			OpenDoor();
		}
	}
}

