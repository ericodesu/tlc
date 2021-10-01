// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InfinitySphereSelectedAxisVector.h"
#include "InfinitySphereDimensionsVector.h"
#include "InfinitySphere.generated.h"

UCLASS()
class UNREAL_API AInfinitySphere : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInfinitySphere();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MainStaticMeshComponent;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* TrailStaticMeshComponent;
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