// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PlayerSlateHUD.h"
#include "UI/PlayerSlateHUDWidget.h"

#include "Engine/Engine.h"

void APlayerSlateHUD::BeginPlay()
{
    Super::BeginPlay();

    if (GEngine && GEngine->GameViewport)
    {
        SAssignNew(PlayerSlateHUDWidget, SPlayerSlateHUDWidget).WidgetOwnerArg(this);

        GEngine->GameViewport->AddViewportWidgetContent(
            SNew(SWeakWidget)
            .PossiblyNullContent(PlayerSlateHUDWidget.ToSharedRef())
        );
    }
}
