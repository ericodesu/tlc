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

FString SPlayerHUDWidget::GetFontLocale(const FontLocales& Locale)
{
    const FString EnumValues[]{
        "",
        "JP"
    };

    return EnumValues[Locale < (sizeof(EnumValues) / sizeof(*EnumValues)) ? Locale : 0].ToUpper();
}

FString SPlayerHUDWidget::GetFontExtension(const FontExtensions& Extension)
{
    const FString EnumValues[]{
        "ttf",
        "otf"
    };

    return EnumValues[Extension < (sizeof(EnumValues) / sizeof(*EnumValues)) ? Extension : 0].ToLower();
}

FSlateFontInfo SPlayerHUDWidget::GenerateSlateFontInfo(
    const FString &FontName,
    const FontExtensions& FontExtension,
    const FontLocales& FontLocale,
    const uint32& FontSize = 24
)
{
    FString FontFileName = GetFontLocale(FontLocale) + FontName + "." + GetFontExtension(FontExtension);
    FString FontDirPath = FPaths::ProjectContentDir() / "UI" / "HUD" / "Faces" / "Raw";
    FString FontFilePath = FontDirPath / FontFileName;

    if (FPaths::DirectoryExists(FontDirPath) == false || FPaths::FileExists(FontFilePath) == false)
    {
        FontFileName = "Roboto-Bold.ttf";
        FontDirPath = FPaths::EngineContentDir() / "Slate" / "Fonts";
        FontFilePath = FontDirPath / FontFileName;
    }

    return FSlateFontInfo(
        FontFilePath,
        FontSize
    );
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
            .Font(GenerateSlateFontInfo(
                "NotoSans-Bold",
                FontExtensions::TTF,
                FontLocales::EN_US
            ))
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
            .Font(GenerateSlateFontInfo(
                "NotoSans-Bold",
                FontExtensions::TTF,
                FontLocales::EN_US
            ))
            .Text(LOCTEXT("ManaStatusLabel", "Mana"))
        ]
    ];
}

#undef LOCTEXT_NAMESPACE