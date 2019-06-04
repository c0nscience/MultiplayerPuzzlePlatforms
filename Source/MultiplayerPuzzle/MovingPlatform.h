// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERPUZZLE_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AMovingPlatform();

	void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere)
	float Speed = 20;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector MoveDirection;

	UPROPERTY(EditAnywhere)
	float Distance = 500;

private:
	FVector StartLocation;

	float DirectionMultiplier = 1;

protected:
	void BeginPlay() override;

};
