// Fill out your copyright notice in the Description page of Project Settings.


#include "CurveTrajectoryMovementComponent.h"

// Sets default values for this component's properties
UCurveTrajectoryMovementComponent::UCurveTrajectoryMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCurveTrajectoryMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	Velocity = InitialAccelleration * GetOwner()->GetActorForwardVector();
}


// Called every frame
void UCurveTrajectoryMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector NextPosition = GetOwner()->GetActorLocation() + Velocity * DeltaTime * DeltaTime * Drag;

	Velocity.Z -= Gravity.Z * DeltaTime;

	FHitResult HitResult;

	if (GetWorld()->LineTraceSingleByChannel(HitResult, GetOwner()->GetActorLocation(), NextPosition, CollisionChannel))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("As Hit Something"));
		GetOwner()->Destroy();
		HitResult.GetActor()->Destroy();
	}

	GetOwner()->SetActorLocation(NextPosition);
	// ...
}

