// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"
#include "../../Widgets/PlayerHUD/PlayerHUDWidget.h"
#include "Engine/Engine.h"

void APlayerHUD::BeginPlay()
{
    Super::BeginPlay();

    if (GEngine && GEngine->GameViewport)
    {
        SAssignNew(PlayerHUDWidget, SPlayerHUDWidget).WidgetOwnerArg(this);

        GEngine->GameViewport->AddViewportWidgetContent(
            SNew(SWeakWidget)
            .PossiblyNullContent(PlayerHUDWidget.ToSharedRef())
        );
    }
}
