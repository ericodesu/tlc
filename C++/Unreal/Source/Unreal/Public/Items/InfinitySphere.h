// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Unreal/Types.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InfinitySphere.generated.h"

UCLASS()
class UNREAL_API AInfinitySphere : public AActor
{
	GENERATED_BODY()
	
public:	
	AInfinitySphere();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MainStaticMeshComponent;
	UPROPERTY(
		EditInstanceOnly,
		Category = "Rotation Properties",
		meta = (DisplayName = "Dimensions")
	)
	FInfinitySphereDimensionsVector RotationDimensions;
	UPROPERTY(
		EditInstanceOnly,
		Category = "Rotation Properties",
		meta = (DisplayName = "Axis")
	)
	FInfinitySphereSelectedAxisVector RotationAxis;
	UPROPERTY(
		EditInstanceOnly,
		Category = "Rotation Properties",
		meta = (
			DisplayName = "Speed",
			ClampMin = "0.0",
			UIMin = "0.0"
		)
	)
	float RotationSpeed;
	UPROPERTY(
		EditInstanceOnly,
		Category = "Rotation Properties",
		meta = (DisplayName = "Angle")
	)
	float RotationAngle;
	float RotationCurrentAngle;
};