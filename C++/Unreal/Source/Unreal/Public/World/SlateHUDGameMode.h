// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SlateHUDGamemode.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL_API ASlateHUDGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASlateHUDGameMode();

	virtual void Tick(float DeltaTime) override;
};
