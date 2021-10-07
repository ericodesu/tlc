// Fill out your copyright notice in the Description page of Project Settings.

#include "World/SlateHUDGameMode.h"
#include "Player/PlayerSlateHUDController.h"
#include "UI/PlayerSlateHUD.h"

ASlateHUDGameMode::ASlateHUDGameMode()
{
    PrimaryActorTick.bCanEverTick = true;

    PlayerControllerClass = APlayerSlateHUDController::StaticClass();
    HUDClass = APlayerSlateHUD::StaticClass();
}

void ASlateHUDGameMode::Tick(float DeltaTime)
{
}