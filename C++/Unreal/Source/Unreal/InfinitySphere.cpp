// Fill out your copyright notice in the Description page of Project Settings.


#include "InfinitySphere.h"


// Sets default values
AInfinitySphere::AInfinitySphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	RootComponent = StaticMeshComponent;

	RotationDimensions = *(new FVector(600.0f, 80.0f, 80.0f));
	RotationAxis = *(new FVector(0.0f, 0.0f, 1.0f));
	RotationSpeed = 300.0f;
}

// Called when the game starts or when spawned
void AInfinitySphere::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AInfinitySphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();

	RotationAngle += DeltaTime * RotationSpeed;

	if (RotationAngle >= 360.0f)
	{
		RotationAngle = 0;
	}

	FVector RotationValue = RotationDimensions.RotateAngleAxis(RotationAngle, RotationAxis);

	NewLocation.X = RotationValue.X;
	NewLocation.Y = RotationValue.Y;
	NewLocation.Z = RotationValue.Z;

	SetActorLocation(NewLocation);
}

