#pragma once

#include "Unreal/Classes/InternalFont.h"

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "PlayerStatus.generated.h"

USTRUCT()
struct FStyles
{
    GENERATED_BODY()

public:
    FORCEINLINE FStyles();

    FORCEINLINE FStyles(FLinearColor InBackgroundColor, FLinearColor InFillColor);

    FORCEINLINE FStyles(FLinearColor InTextColor);

    FLinearColor BackgroundColor;

    FLinearColor FillColor;

    FLinearColor TextColor;
};

FORCEINLINE FStyles::FStyles()
{}

FORCEINLINE FStyles::FStyles(FLinearColor InBackgroundColor, FLinearColor InFillColor)
    : BackgroundColor(InBackgroundColor), FillColor(InFillColor)
{}

FORCEINLINE FStyles::FStyles(FLinearColor InTextColor)
    : TextColor(InTextColor)
{}

USTRUCT()
struct FDimensions2D
{
    GENERATED_BODY()

public:
    FORCEINLINE FDimensions2D();

    FORCEINLINE FDimensions2D(float InWidth, float InHeight);

    float Width;
    float Height;
};

FORCEINLINE FDimensions2D::FDimensions2D()
{}

FORCEINLINE FDimensions2D::FDimensions2D(float InWidth, float InHeight)
    : Width(InWidth), Height(InHeight)
{}

USTRUCT()
struct FTextConfiguration
{
    GENERATED_BODY()

public:
    FORCEINLINE FTextConfiguration();

    FORCEINLINE FTextConfiguration(
        FSlateFontInfo InFont,
        FStyles InStyles,
        FDimensions2D InDimensions
    );

    FSlateFontInfo Font;

    FStyles Styles;

    FDimensions2D Dimensions;
};

FORCEINLINE FTextConfiguration::FTextConfiguration()
{}

FORCEINLINE FTextConfiguration::FTextConfiguration(
    FSlateFontInfo InFont,
    FStyles InStyles,
    FDimensions2D InDimensions
)
    : Font(InFont),
      Styles(InStyles),
      Dimensions(InDimensions)
{}

USTRUCT()
struct FGraphicalConfiguration
{
    GENERATED_BODY()

public:
    FORCEINLINE FGraphicalConfiguration();

    FORCEINLINE FGraphicalConfiguration(
        FStyles InStyles,
        FDimensions2D InDimensions
    );

    FStyles Styles;

    FDimensions2D Dimensions;
};

FORCEINLINE FGraphicalConfiguration::FGraphicalConfiguration()
{}

FORCEINLINE FGraphicalConfiguration::FGraphicalConfiguration(
    FStyles InStyles,
    FDimensions2D InDimensions
)
    : Styles(InStyles),
      Dimensions(InDimensions)
{}

USTRUCT()
struct FPlayerTextStatus
{
    GENERATED_BODY()

public:
    FORCEINLINE FPlayerTextStatus();

    FORCEINLINE FPlayerTextStatus(FTextConfiguration InConfiguration, FString InContent);

    FTextConfiguration Configuration;

    FText Content;
};

FORCEINLINE FPlayerTextStatus::FPlayerTextStatus()
{}

FORCEINLINE FPlayerTextStatus::FPlayerTextStatus(FTextConfiguration InConfiguration, FString InContent)
    : Configuration(InConfiguration), Content(FText::FromString(InContent))
{}

USTRUCT()
struct FPlayerGraphicalStatus
{
    GENERATED_BODY()

public:
    FORCEINLINE FPlayerGraphicalStatus();

    FORCEINLINE FPlayerGraphicalStatus(FGraphicalConfiguration InConfiguration);

    FORCEINLINE FPlayerGraphicalStatus(
        FGraphicalConfiguration InConfiguration,
        float InProgress
    );

    TOptional<float> GetProgress();

    FGraphicalConfiguration Configuration;

    float Progress;
};

FORCEINLINE FPlayerGraphicalStatus::FPlayerGraphicalStatus()
{}

FORCEINLINE FPlayerGraphicalStatus::FPlayerGraphicalStatus(FGraphicalConfiguration InConfiguration)
    : Configuration(InConfiguration), Progress(100.0f)
{}

FORCEINLINE FPlayerGraphicalStatus::FPlayerGraphicalStatus(
    FGraphicalConfiguration InConfiguration,
    float InProgress
)
    : Configuration(InConfiguration), Progress(InProgress)
{}

inline TOptional<float> FPlayerGraphicalStatus::GetProgress()
{
    float ConvertedProgress = this->Progress / 100.0f;

    if (ConvertedProgress < 0.0f)
    {
        ConvertedProgress = 0.0f;
    }
    else if (ConvertedProgress > 1.0f)
    {
        ConvertedProgress = 1.0f;
    }

    return ConvertedProgress;
}