// Fill out your copyright notice in the Description page of Project Settings.

#include "World/HUDGameMode.h"
#include "Player/PlayerHUDController.h"
#include "UI/PlayerHUD.h"

AHUDGameMode::AHUDGameMode()
{
    PrimaryActorTick.bCanEverTick = true;

    PlayerControllerClass = APlayerHUDController::StaticClass();
    HUDClass = APlayerHUD::StaticClass();
}

void AHUDGameMode::Tick(float DeltaTime)
{
}