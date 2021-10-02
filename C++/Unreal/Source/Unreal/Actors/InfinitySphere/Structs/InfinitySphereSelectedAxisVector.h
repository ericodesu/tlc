#pragma once

#include "CoreMinimal.h"
#include "InfinitySphereSelectedAxisVector.generated.h"

USTRUCT()
struct FInfinitySphereSelectedAxisVector
{
    GENERATED_BODY()

public:
    /** Vector's X activation status. */
    UPROPERTY(EditInstanceOnly, meta = (DisplayName = "X"))
    bool bIsXSelected;
    /** Vector's Y activation status. */
    UPROPERTY(EditInstanceOnly, meta = (DisplayName = "Y"))
    bool bIsYSelected;
    /** Vector's Z activation status. */
    UPROPERTY(EditInstanceOnly, meta = (DisplayName = "Z"))
    bool bIsZSelected;

    FORCEINLINE FInfinitySphereSelectedAxisVector();

    /**
     * @param InX X initial activation status.
     * @param InY Y initial activation status.
     * @param InZ Z initial activation status.
     */
    FORCEINLINE FInfinitySphereSelectedAxisVector(
        bool bInIsXSelected,
        bool bInIsYSelected,
        bool bInIsZSelected
    );

    /**
     * @returns FVector.
     */
    FVector ConvertToFVector();
};

inline FVector FInfinitySphereSelectedAxisVector::ConvertToFVector()
{
    return *(new FVector(
        (float)this->bIsXSelected,
        (float)this->bIsYSelected,
        (float)this->bIsZSelected
    ));
}

FORCEINLINE FInfinitySphereSelectedAxisVector::FInfinitySphereSelectedAxisVector()
{}

FORCEINLINE FInfinitySphereSelectedAxisVector::FInfinitySphereSelectedAxisVector(
    bool bInIsXSelected,
    bool bInIsYSelected,
    bool bInIsZSelected
)
    : bIsXSelected(bInIsXSelected), bIsYSelected(bInIsYSelected), bIsZSelected(bInIsZSelected)
{}