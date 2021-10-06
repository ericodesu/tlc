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
    FStyles HealthBarStyles = FStyles(
        FLinearColor(FVector(28.0f, 237.0f, 70.0f)),
        FLinearColor(FVector(209.0f, 209.0f, 209.0f))
    );

    FDimensions2D HealthBarDimensions = FDimensions2D(100.0f, 300.0f);

    FGraphicalConfiguration HealthBarConfiguration = FGraphicalConfiguration(
        HealthBarStyles,
        HealthBarDimensions
    );

    this->PlayerHealthBar = FPlayerGraphicalStatus(
        HealthBarConfiguration,
        100.0f
    );

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
    FInternalFont ManaBarFont = FInternalFont(
        "NotoSans-Light",
        EFontLocales::JP,
        EFontExtensions::OTF,
        26
    );

    FStyles ManaBarStyles = FStyles(FLinearColor(FVector(255.0f, 255.0f, 255.0f)));

    FDimensions2D ManaBarDimensions = FDimensions2D(100.0f, 300.0f);

    FTextConfiguration ManaBarConfiguration = FTextConfiguration(
        ManaBarFont.GetFontInfo(),
        ManaBarStyles,
        ManaBarDimensions
    );

    this->PlayerManaBar = FPlayerTextStatus(
        ManaBarConfiguration,
        "何か"
    );

    FooterBox->AddSlot()
    [
        SNew(SVerticalBox)
        + SVerticalBox::Slot()
        .VAlign(VAlign_Bottom)
        [
            SNew(STextBlock)
            .ColorAndOpacity(this->PlayerManaBar.Configuration.Styles.TextColor)
            .Font(this->PlayerManaBar.Configuration.Font)
            .Text(LOCTEXT("ManaStatusLabel", "何か"))
        ]
    ];
}

#undef LOCTEXT_NAMESPACE