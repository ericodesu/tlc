#pragma once

#include "Unreal/Classes/InternalFont.h"

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "PlayerStatus.generated.h"

USTRUCT()
struct FDimensions2D
{
    GENERATED_BODY()

public:
    uint32 Width;
    uint32 Height;
};

USTRUCT()
struct FTextConfiguration
{
    GENERATED_BODY()

public:
    FORCEINLINE FTextConfiguration();

    FORCEINLINE FTextConfiguration(FDimensions2D InDimensions, FSlateFontInfo InFont);

    FDimensions2D Dimensions;

    FSlateFontInfo Font;
};

FORCEINLINE FTextConfiguration::FTextConfiguration()
{}

FORCEINLINE FTextConfiguration::FTextConfiguration(FDimensions2D InDimensions, FSlateFontInfo InFont)
    : Dimensions(InDimensions), Font(InFont)
{}

USTRUCT()
struct FGraphicalConfiguration
{
    GENERATED_BODY()

public:
    FORCEINLINE FGraphicalConfiguration();

    FORCEINLINE FGraphicalConfiguration(FSlateColor InBackgroundColor, FDimensions2D InDimensions);

    FSlateColor BackgroundColor;

    FDimensions2D Dimensions;
};

FORCEINLINE FGraphicalConfiguration::FGraphicalConfiguration()
{}

FORCEINLINE FGraphicalConfiguration::FGraphicalConfiguration(FSlateColor InBackgroundColor, FDimensions2D InDimensions)
    : BackgroundColor(InBackgroundColor), Dimensions(InDimensions)
{}

USTRUCT()
struct FPlayerTextStatus
{
    GENERATED_BODY()

public:
    FORCEINLINE FPlayerTextStatus();

    FORCEINLINE FPlayerTextStatus(FString InContent, FTextConfiguration InConfiguration);

    FString Content;

    FTextConfiguration Configuration;
};

FORCEINLINE FPlayerTextStatus::FPlayerTextStatus()
{}

FORCEINLINE FPlayerTextStatus::FPlayerTextStatus(FString InContent, FTextConfiguration InConfiguration)
    : Content(InContent), Configuration(InConfiguration)
{}

USTRUCT()
struct FPlayerGraphicalStatus
{
    GENERATED_BODY()

public:
    FORCEINLINE FPlayerGraphicalStatus();

    FORCEINLINE FPlayerGraphicalStatus(FGraphicalConfiguration InConfiguration);

    FGraphicalConfiguration Configuration;
};

FORCEINLINE FPlayerGraphicalStatus::FPlayerGraphicalStatus()
{}

FORCEINLINE FPlayerGraphicalStatus::FPlayerGraphicalStatus(FGraphicalConfiguration InConfiguration)
    : Configuration(InConfiguration)
{}