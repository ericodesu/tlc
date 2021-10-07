// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayerSlateHUD.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL_API APlayerSlateHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	TSharedPtr<class SPlayerSlateHUDWidget> PlayerSlateHUDWidget;
};
