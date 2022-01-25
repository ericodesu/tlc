#pragma once

#include "CoreMinimal.h"
#include "InifinitySphereSelectedAxis.generated.h"

USTRUCT()
struct FInifinitySphereSelectedAxis
{
    GENERATED_BODY()

public:
    UPROPERTY(EditInstanceOnly, meta = (DisplayName = "X"))
    bool bIsXSelected;

    UPROPERTY(EditInstanceOnly, meta = (DisplayName = "Y"))
    bool bIsYSelected;

    UPROPERTY(EditInstanceOnly, meta = (DisplayName = "Z"))
    bool bIsZSelected;

    FORCEINLINE FInifinitySphereSelectedAxis();

    /**
     * @param InX X initial activation status.
     * @param InY Y initial activation status.
     * @param InZ Z initial activation status.
     */
    FORCEINLINE FInifinitySphereSelectedAxis(
        bool bInIsXSelected,
        bool bInIsYSelected,
        bool bInIsZSelected
    );

    /**
     * @returns FVector.
     */
    FVector ConvertToFVector();
};

inline FVector FInifinitySphereSelectedAxis::ConvertToFVector()
{
    return *(new FVector(
        (float)this->bIsXSelected,
        (float)this->bIsYSelected,
        (float)this->bIsZSelected
    ));
}

FORCEINLINE FInifinitySphereSelectedAxis::FInifinitySphereSelectedAxis()
{}

FORCEINLINE FInifinitySphereSelectedAxis::FInifinitySphereSelectedAxis(
    bool bInIsXSelected,
    bool bInIsYSelected,
    bool bInIsZSelected
)
    : bIsXSelected(bInIsXSelected), bIsYSelected(bInIsYSelected), bIsZSelected(bInIsZSelected)
{}