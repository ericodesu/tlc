#pragma once

#include "CoreMinimal.h"
#include "InfinitySphereDimensions.generated.h"

USTRUCT()
struct FInfinitySphereDimensions
{
    GENERATED_BODY()

public:
    UPROPERTY(EditInstanceOnly)
    float Radius;

    UPROPERTY(EditInstanceOnly)
    float Height;

    FORCEINLINE FInfinitySphereDimensions();

    /**
     * @param InRadius radius initial value.
     * @param InHeight Height initial value.
     */
    FORCEINLINE FInfinitySphereDimensions(float InRadius, float InHeight);

    FVector ConvertToFVector();
};

FORCEINLINE FInfinitySphereDimensions::FInfinitySphereDimensions()
{}

FORCEINLINE FInfinitySphereDimensions::FInfinitySphereDimensions(float InRadius, float InHeight)
    : Radius(InRadius), Height(InHeight)
{}

inline FVector FInfinitySphereDimensions::ConvertToFVector()
{
    return *(new FVector(
        (float)this->Radius,
        (float)this->Height,
        (float)this->Height
    ));
}
