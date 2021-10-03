#pragma once

#include "CoreMinimal.h"
#include "Types.generated.h"

USTRUCT()
struct FInfinitySphereSelectedAxisVector
{
    GENERATED_BODY()

public:
    UPROPERTY(EditInstanceOnly, meta = (DisplayName = "X"))
    bool bIsXSelected;

    UPROPERTY(EditInstanceOnly, meta = (DisplayName = "Y"))
    bool bIsYSelected;

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

USTRUCT()
struct FInfinitySphereDimensionsVector
{
    GENERATED_BODY()

public:
    UPROPERTY(EditInstanceOnly)
    float Radius;

    UPROPERTY(EditInstanceOnly)
    float Height;

    FORCEINLINE FInfinitySphereDimensionsVector();

    /**
     * @param InRadius radius initial value.
     * @param InHeight Height initial value.
     */
    FORCEINLINE FInfinitySphereDimensionsVector(float InRadius, float InHeight);

    FVector ConvertToFVector();
};

inline FVector FInfinitySphereDimensionsVector::ConvertToFVector()
{
    return *(new FVector(
        (float)this->Radius,
        (float)this->Height,
        (float)this->Height
    ));
}

FORCEINLINE FInfinitySphereDimensionsVector::FInfinitySphereDimensionsVector()
{}

FORCEINLINE FInfinitySphereDimensionsVector::FInfinitySphereDimensionsVector(float InRadius, float InHeight)
    : Radius(InRadius), Height(InHeight)
{}