// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
//#include "Tank.h"
#include "Engine/World.h"
#include "TankPlayerController.generated.h"	//Must be the last include

//forward declarations
class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float CrossHairXLocation = 0.5;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float CrossHairYLocation = 0.33333;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float LineTraceRange = 1000000;

	ATank* GetControlledTank() const;

	void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;



private:
	//Start the tank barrel moving towards crosshair so that shots fire where crosshair intersects the world
	void AimTowardsCrosshair();

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	FVector GetLookVectorEnd() const;

};
