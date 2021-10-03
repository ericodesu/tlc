// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HUDGamemode.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL_API AHUDGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AHUDGameMode();

	virtual void Tick(float DeltaTime) override;
};
