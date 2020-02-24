// Fill out your copyright notice in the Description page of Project Settings.

//Generated Include
#include "TankAIController.h"
//Manual Includes
#include "BattleTank.h"
#include "Tank.h"
// Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (ensure(PlayerTank))
	{
		//Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius); //TODO check radius is in cm

		//Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		
		//Fire every frame
		ControlledTank->Fire();  //TODO Don't fire every frame, limit fire rate
	}
	
}