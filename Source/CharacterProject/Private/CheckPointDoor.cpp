// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckPointDoor.h"



// Sets default values
ACheckPointDoor::ACheckPointDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("root"));
	RootComponent = Root;
	
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("KeyHolder"));
	Box->SetupAttachment(Root);

	CheckPoint = CreateDefaultSubobject<USceneComponent>(TEXT("CheckPoint"));
	CheckPoint->SetupAttachment(Root);

	Interactable = CreateDefaultSubobject<UInteractableDoor>(TEXT("Interactable"));

}

// Called when the game starts or when spawned
void ACheckPointDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACheckPointDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ACheckPointDoor::CheckKey(FInteractorPayload Payload)
{
	if (APinko* Character = Cast<APinko>(Payload.Interactor))
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

void ACheckPointDoor::Interacted(FInteractorPayload Payload)
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

