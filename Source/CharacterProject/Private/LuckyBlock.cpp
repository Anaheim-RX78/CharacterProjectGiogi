// Fill out your copyright notice in the Description page of Project Settings.


#include "LuckyBlock.h"

#include "CollectableSpawner.h"


// Sets default values
ALuckyBlock::ALuckyBlock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>("Sphere Component");
	RootComponent = SphereComp;
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &ALuckyBlock::OnActorOverlap);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh Component");
	StaticMeshComp->SetupAttachment(SphereComp);
	

}

// Called when the game starts or when spawned
void ALuckyBlock::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALuckyBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALuckyBlock::OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (UAbilityComponent* AbilityComponent = OtherActor->GetComponentByClass<UAbilityComponent>())
	{
		AbilityComponent->AddRandomAbility();
		UGameplayStatics::PlaySound2D(GetWorld(), PickupSound);
		if (MySpawner)
		{
			MySpawner->SetSpawnedActorNull();
		}
		Destroy();
	}
}

void ALuckyBlock::SetSpawner(ACollectableSpawner* Spawner)
{
	MySpawner = Spawner;
}
