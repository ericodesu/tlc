// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/InfinitySphere.h"

AInfinitySphere::AInfinitySphere()
{
	PrimaryActorTick.bCanEverTick = true;

	MainStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MainStaticMeshComponent"));
	RootComponent = MainStaticMeshComponent;

	RotationDimensions = *(new FInfinitySphereDimensions(0.0f, 0.0f));
	RotationAxis = *(new FInifinitySphereSelectedAxis(false, false, false));
	RotationSpeed = 0.0f;
	RotationAngle = 0.0f;
}

void AInfinitySphere::BeginPlay()
{
	Super::BeginPlay();

	RotationCurrentAngle = 0;
}

void AInfinitySphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (RotationAngle > 0)
	{
		if (RotationCurrentAngle >= RotationAngle)
		{
			RotationCurrentAngle = 0;
		}

		RotationCurrentAngle += DeltaTime * RotationSpeed;
	}
	else if (RotationAngle < 0)
	{
		if (RotationCurrentAngle <= RotationAngle)
		{
			RotationCurrentAngle = 0;
		}

		RotationCurrentAngle -= DeltaTime * RotationSpeed;
	}

	FVector NewLocation = GetActorLocation();
	FVector RotationValue = RotationDimensions
		.ConvertToFVector()
		.RotateAngleAxis(
			RotationCurrentAngle,
			RotationAxis.ConvertToFVector()
		);

	NewLocation.X = RotationValue.X;
	NewLocation.Y = RotationValue.Y;
	NewLocation.Z = RotationValue.Z;

	SetActorLocation(NewLocation);
}

