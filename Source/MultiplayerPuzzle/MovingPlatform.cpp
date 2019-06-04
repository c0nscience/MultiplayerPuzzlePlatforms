// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

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
		// const auto GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
		const auto Direction = TargetLocation.GetSafeNormal();
		ActorLocation += Speed * DeltaSeconds * Direction;

		SetActorLocation(ActorLocation);
	}
}
