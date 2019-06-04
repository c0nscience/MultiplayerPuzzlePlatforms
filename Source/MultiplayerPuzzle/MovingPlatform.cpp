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
		GlobalStartLocation = GetActorLocation();
		GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
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
		const auto Distance = (GlobalTargetLocation - GlobalStartLocation).Size();
		const auto CurrentDistance = (ActorLocation - GlobalStartLocation).Size();
		
		if (CurrentDistance > Distance)
		{
			const auto Swap = GlobalStartLocation;
			GlobalStartLocation = GlobalTargetLocation;
			GlobalTargetLocation = Swap;
		}

		const auto Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
		ActorLocation += Speed * DeltaSeconds * Direction;

		SetActorLocation(ActorLocation);
	}
}
