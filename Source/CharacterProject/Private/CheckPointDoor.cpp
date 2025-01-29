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
	if (Cast<APinko>(Payload.Interactor))
	{
		return true;
	}
	
	return false;
	
}

void ACheckPointDoor::Interacted(FInteractorPayload Payload)
{
	if (CheckKey(Payload))
	{
		OpenDoor();
	}
}

