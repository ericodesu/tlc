// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PlayerSlateHUDWidget.h"

#include "Components/Widget.h"

#define LOCTEXT_NAMESPACE "PlayerSlateHUD"

void SPlayerSlateHUDWidget::Construct(const FArguments& InArgs)
{
    this->BarDimensions = FDimensions2D(300.0f, 100.0f);

    this->ChildSlot
    [
        SNew(SOverlay)
        + SOverlay::Slot()
        .HAlign(HAlign_Fill)
        .VAlign(VAlign_Fill)
        [
            SAssignNew(this->WrapperBox, SVerticalBox)
        ]
    ];

    this->WrapperBox->AddSlot()
    [
        SAssignNew(this->FooterBox, SHorizontalBox)
    ];

    AttachEssentialStatus();
}

void SPlayerSlateHUDWidget::AttachEssentialStatus()
{
    AttachHealthStatusBar();
    AttachManaStatusBar();
}

void SPlayerSlateHUDWidget::AttachHealthStatusBar()
{
    FStyles BarStyles = FStyles(
        FLinearColor(0.0f, 0.0f, 0.0f, 1.0f),
        FLinearColor(74.0f / 255.0f, 154.0f / 255.0f, 54.0f / 255.0f, 1.0f)
    );

    FGraphicalConfiguration BarConfiguration = FGraphicalConfiguration(
        BarStyles,
        this->BarDimensions
    );

    this->PlayerHealthBar = FPlayerGraphicalStatus(
        BarConfiguration,
        70.0f
    );

    this->FooterBox->AddSlot()
    [
        SNew(SBox)
        .VAlign(VAlign_Bottom)
        .HAlign(HAlign_Left)
        .HeightOverride(this->PlayerHealthBar.Configuration.Dimensions.Height)
        .WidthOverride(this->PlayerHealthBar.Configuration.Dimensions.Width)
        [
            SNew(SProgressBar)
            .BarFillType(EProgressBarFillType::LeftToRight)
            .FillColorAndOpacity(this->PlayerHealthBar.Configuration.Styles.FillColor)
            .Percent_Lambda([&]() {
                return this->PlayerHealthBar.GetProgress();
            })
        ]
    ];
}

void SPlayerSlateHUDWidget::AttachManaStatusBar()
{
    FStyles BarStyles = FStyles(
        FLinearColor(0.0f, 0.0f, 0.0f, 1.0f),
        FLinearColor(47.0f / 255.0f, 144.0f / 255.0f, 235.0f / 255.0f, 1.0f)
    );

    FGraphicalConfiguration BarConfiguration = FGraphicalConfiguration(
        BarStyles,
        this->BarDimensions
    );

    this->PlayerManaBar = FPlayerGraphicalStatus(
        BarConfiguration,
        90.0f
    );

    this->FooterBox->AddSlot()
    [
        SNew(SBox)
        .VAlign(VAlign_Bottom)
        .HAlign(HAlign_Right)
        .HeightOverride(this->PlayerManaBar.Configuration.Dimensions.Height)
        .WidthOverride(this->PlayerManaBar.Configuration.Dimensions.Width)
        [
            SNew(SProgressBar)
            .BarFillType(EProgressBarFillType::RightToLeft)
            .FillColorAndOpacity(this->PlayerManaBar.Configuration.Styles.FillColor)
            .Percent_Lambda([&](){
                return this->PlayerManaBar.GetProgress();
            })
        ]
    ];
}

#undef LOCTEXT_NAMESPACE