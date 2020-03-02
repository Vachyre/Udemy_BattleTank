// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::BeginPlay()
{
	Super::BeginPlay(); //Needed for begin play to run!
}

// Called when the Gun Fires
void ATank::Fire()
{
	if (!ensure(Barrel)) { return; }
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (isReloaded)
	{
		//spawn a projectile at the tip of the barrel
		FVector ProjectileSpawn = Barrel->GetSocketLocation(FName("Projectile"));
		FRotator ProjectileRotation = Barrel->GetSocketRotation(FName("Projectile"));
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			ProjectileSpawn,
			ProjectileRotation);

		Projectile->LaunchProjectile(Launchspeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}

