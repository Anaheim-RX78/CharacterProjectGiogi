// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectableItem.h"

// Sets default values
ACollectableItem::ACollectableItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	capsule = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	capsule->SetupAttachment(GetRootComponent());
	capsule->OnComponentBeginOverlap.AddDynamic(this, &ACollectableItem::OnActorOverlap);

}

// Called when the game starts or when spawned
void ACollectableItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACollectableItem::OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ACasurus* Character = Cast<ACasurus>(OtherActor))
	{
		UGameplayStatics::PlaySound2D(GetWorld(), PickUpSound);
		if (MySpawner)
		{
			// Reset The Reference of This Actor In The Spawner
			MySpawner->SetSpawnedActorNull();
		}
		PickUp(Character);
	}
	
}

void ACollectableItem::SetSpawner(ACollectableSpawner* Spawner)
{
	MySpawner = Spawner;
}

void ACollectableItem::PickUp(ACasurus* Character)
{
	//Do Something in the Childs
}

// Called every frame
void ACollectableItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
