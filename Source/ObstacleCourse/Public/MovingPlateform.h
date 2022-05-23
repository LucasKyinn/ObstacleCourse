// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlateform.generated.h"

UCLASS()
class OBSTACLECOURSE_API AMovingPlateform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlateform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	FVector GetMovementVelocity();

	UFUNCTION(BlueprintCallable)
	void SetMovementVelocity(FVector NewVelocity);
private:
	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector MovementVelocity = FVector(1, 0, 0); //Velocity

	UPROPERTY(EditAnywhere, Category = "Movement")
	FRotator RotationVelocity; //RotationSpeed

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MaxMovementDistance = 250.0f;

	UPROPERTY(VisibleAnywhere, Category = "Movement")
	double MovingDistance;

	FVector StartingLocation;

	void MovePlatform(float DeltaTime);

	void RotatePlatform(float DeltaTime);
};
