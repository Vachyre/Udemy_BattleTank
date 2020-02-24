// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"  // put new includes above

class UTankBarrel;  // Forward Declarations
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	void AimAt(FVector HitLocation);

	//UFUNCTION(BlueprintCallable, Category = Setup)


	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

	// TODO Remove once firing is moved to aiming component
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float Launchspeed = 5000; // TODO Find sensible launch speed
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 2;
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;
	virtual void BeginPlay() override;

public:	

private:
	// TODO Get rid of these!
	UTankBarrel* Barrel = nullptr;
//	UTankTrack* LeftTrack = nullptr;
//	UTankTrack* RightTrack = nullptr;

	double LastFireTime = 0;
};
