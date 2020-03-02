// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
//#include "Tank.h"
#include "TankAIController.generated.h"

//Forward Declarations
class UTankAimingComponent;
class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// How close should the AI tank stop
	float AcceptanceRadius = 3000;
};
