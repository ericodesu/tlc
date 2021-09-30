// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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
	UStaticMeshComponent* StaticMeshComponent;
	UPROPERTY(
		EditInstanceOnly,
		Category = "Shphere Status",
		meta = (
			DisplayName = "Dimensions",
			ClampMin = "0.0",
			UIMin = "0.0"
		)
	)
	FVector RotationDimensions;
	UPROPERTY(
		EditInstanceOnly,
		Category = "Shphere Status",
		meta = (
			DisplayName = "Rotarion Axis",
			ClampMin = "0.0",
			UIMin = "0.0",
			ClampMax = "1.0",
			UIMax = "1.0"
		)
	)
	FVector RotationAxis;
	UPROPERTY(
		EditInstanceOnly,
		Category = "Shphere Status",
		meta = (
			DisplayName = "Speed",
			ClampMin = "0.0",
			UIMin = "0.0"
		)
	)
	float RotationSpeed;
	float RotationAngle;
};
