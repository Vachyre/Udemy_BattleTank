// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//Enum for aiming state
UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Firing
};

//Forward Declarations
class UTankBarrel;
class UTankTurret;

// Holds Barrel's properties and elevation method 
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector HitLocation);
	void Fire();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);
	//initilise tank barrel & Turret

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float Launchspeed = 5000; // TODO Find sensible launch speed

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Firing;


private:
	UTankBarrel* Barrel = nullptr; //TODO stop this becoming blank!
	UTankTurret* Turret = nullptr;


	void MoveBarrelTowards(FVector AimDirection);
};