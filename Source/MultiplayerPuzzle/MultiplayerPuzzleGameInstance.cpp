// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerPuzzleGameInstance.h"

#include <Engine/Engine.h>

void UMultiplayerPuzzleGameInstance::Init()
{

}

void UMultiplayerPuzzleGameInstance::Host() const
{
	const auto Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, TEXT("Hosting"));

	const auto World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
}

void UMultiplayerPuzzleGameInstance::Join(FString& Address) const
{
	const auto Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));

}
