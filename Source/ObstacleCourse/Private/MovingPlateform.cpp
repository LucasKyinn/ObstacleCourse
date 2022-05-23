// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlateform.h"

#include <Kismet/GameplayStatics.h>
// Sets default values
AMovingPlateform::AMovingPlateform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlateform::BeginPlay()
{
	Super::BeginPlay();

	StartingLocation = GetActorLocation();


}

// Called every frame
void AMovingPlateform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);

}

FVector AMovingPlateform::GetMovementVelocity()
{
	return MovementVelocity;
}

void AMovingPlateform::SetMovementVelocity(FVector NewVelocity)
{
	MovementVelocity = NewVelocity;
}

void AMovingPlateform::MovePlatform(float DeltaTime)
{
	//SetActorLocation(GetActorLocation()+ MovementVelocity);
	FVector CurentLocation = GetActorLocation();

	MovingDistance = FVector::Dist(CurentLocation, StartingLocation);
	if (MovingDistance > MaxMovementDistance) {

		//FString OvershotString = FString(GetName());
		//float overshoot = MovingDistance - MaxMovementDistance;
		//UE_LOG(LogTemp, Display, TEXT("ActorName : %s Overshot by : %f "), *OvershotString, overshoot);


		StartingLocation = StartingLocation + MovementVelocity.GetSafeNormal() * MaxMovementDistance;
		SetActorLocation(StartingLocation);
		MovementVelocity = -MovementVelocity;

	}

	SetActorLocation(CurentLocation + MovementVelocity * DeltaTime);
}

void AMovingPlateform::RotatePlatform(float DeltaTime)
{
	FRotator CurrentRotation = GetActorRotation();
	CurrentRotation = CurrentRotation + RotationVelocity * DeltaTime;
	SetActorRotation(CurrentRotation);

}

