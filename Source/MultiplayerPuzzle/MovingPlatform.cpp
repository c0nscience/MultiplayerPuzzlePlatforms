// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"
#include <string>

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}


void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		StartLocation = GetActorLocation();
		SetReplicates(true);
		SetReplicateMovement(true);
	}
}

void AMovingPlatform::Tick(const float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (HasAuthority())
	{
		auto ActorLocation = GetActorLocation();
		const auto Direction = MoveDirection.GetSafeNormal();
		const auto CurrentDistance = (ActorLocation - StartLocation).Size();
		
		UE_LOG(LogTemp, Warning, TEXT("Dist %f"), CurrentDistance)
		if ((CurrentDistance > Distance) && DirectionMultiplier > 0)
		{
			DirectionMultiplier = -1;
		} else if ((CurrentDistance < 10) && DirectionMultiplier < 0)
		{
			DirectionMultiplier = 1;
		}

		UE_LOG(LogTemp, Warning, TEXT("Multiplier: %f"), DirectionMultiplier)
		ActorLocation += DirectionMultiplier * Speed * DeltaSeconds * Direction;

		SetActorLocation(ActorLocation);
	}
}
