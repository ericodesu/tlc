#pragma once

#include "CoreMinimal.h"
#include "InfinitySphereDimensionsVector.generated.h"

USTRUCT()
struct FInfinitySphereDimensionsVector
{
    GENERATED_BODY()

public:
    /** Sphere radius in centimeters. */
    UPROPERTY(EditInstanceOnly)
    float Radius;
    /** Sphere height in centimeters. */
    UPROPERTY(EditInstanceOnly)
    float Height;

    FORCEINLINE FInfinitySphereDimensionsVector();

    /**
     * @param InRadius radius initial value.
     * @param InHeight Height initial value.
     */
    FORCEINLINE FInfinitySphereDimensionsVector(float InRadius, float InHeight);

    /**
    * @returns FVector.
    */
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