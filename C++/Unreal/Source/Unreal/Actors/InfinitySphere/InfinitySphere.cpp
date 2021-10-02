// Fill out your copyright notice in the Description page of Project Settings.


#include "InfinitySphere.h"

// Sets default values
AInfinitySphere::AInfinitySphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MainStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MainStaticMeshComponent"));
	RootComponent = MainStaticMeshComponent;

	RotationDimensions = *(new FInfinitySphereDimensionsVector(0.0f, 0.0f));
	RotationAxis = *(new FInfinitySphereSelectedAxisVector(false, false, false));
	RotationSpeed = 0.0f;
	RotationAngle = 0.0f;
}

// Called when the game starts or when spawned
void AInfinitySphere::BeginPlay()
{
	Super::BeginPlay();

	RotationCurrentAngle = 0;
}

// Called every frame
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

