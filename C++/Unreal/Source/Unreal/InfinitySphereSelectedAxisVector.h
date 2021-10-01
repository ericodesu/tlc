#pragma once

#include "CoreMinimal.h"
#include "InfinitySphereSelectedAxisVector.generated.h"

USTRUCT()
struct FInfinitySphereSelectedAxisVector
{
    GENERATED_BODY()

public:
    /** Vector's X activation status. */
    UPROPERTY(EditInstanceOnly)
    bool X;
    /** Vector's Y activation status. */
    UPROPERTY(EditInstanceOnly)
    bool Y;
    /** Vector's Z activation status. */
    UPROPERTY(EditInstanceOnly)
    bool Z;

    FORCEINLINE FInfinitySphereSelectedAxisVector();

    /**
     * @param InX X initial activation status.
     * @param InY Y initial activation status.
     * @param InZ Z initial activation status.
     */
    FORCEINLINE FInfinitySphereSelectedAxisVector(bool InX, bool InY, bool InZ);

    /**
     * @returns FVector.
     */
    FVector ConvertToFVector();
};

inline FVector FInfinitySphereSelectedAxisVector::ConvertToFVector()
{
    return *(new FVector(
        (float)this->X,
        (float)this->Y,
        (float)this->Z
    ));
}

FORCEINLINE FInfinitySphereSelectedAxisVector::FInfinitySphereSelectedAxisVector()
{}

FORCEINLINE FInfinitySphereSelectedAxisVector::FInfinitySphereSelectedAxisVector(bool InX, bool InY, bool InZ)
    : X(InX), Y(InY), Z(InZ)
{}