// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PlayerHUDWidget.h"

#include "Components/Widget.h"

#define LOCTEXT_NAMESPACE "PlayerHUD"

void SPlayerHUDWidget::Construct(const FArguments& InArgs)
{
    ChildSlot
    [
        SNew(SOverlay)
        + SOverlay::Slot()
        .HAlign(HAlign_Fill)
        .VAlign(VAlign_Fill)
        [
            SAssignNew(WrapperBox, SVerticalBox)
        ]
    ];

    WrapperBox->AddSlot()
    [
        SAssignNew(FooterBox, SHorizontalBox)
    ];

    AttachEssentialStatus();
}

void SPlayerHUDWidget::AttachEssentialStatus()
{
    AttachHealthStatusBar();
    AttachManaStatusBar();
}

void SPlayerHUDWidget::AttachHealthStatusBar()
{
    FooterBox->AddSlot()
    [
        SNew(SVerticalBox)
        + SVerticalBox::Slot()
        .VAlign(VAlign_Bottom)
        [
            SNew(STextBlock)
            .Font(FInternalFont(
                "NotoSans-Bold",
                EFontLocales::EN_US,
                EFontExtensions::TTF,
                32
            ).GetFontInfo())
            .Text(LOCTEXT("LifeStatusLabel", "Life"))
        ]
    ];
}

void SPlayerHUDWidget::AttachManaStatusBar()
{
    FooterBox->AddSlot()
    [
        SNew(SVerticalBox)
        + SVerticalBox::Slot()
        .VAlign(VAlign_Bottom)
        [
            SNew(STextBlock)
            .Font(FInternalFont(
                "NotoSans-Light",
                EFontLocales::JP,
                EFontExtensions::OTF,
                32
            ).GetFontInfo())
            .Text(LOCTEXT("ManaStatusLabel", "なにーーーー"))
        ]
    ];
}

#undef LOCTEXT_NAMESPACE