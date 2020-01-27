// Fill out your copyright notice in the Description page of Project Settings.

//Generated Include
#include "TankAIController.h"
//Manual Includes
#include "BattleTank.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		//Move towards player

		//Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		
		//Fire every frame
		ControlledTank->Fire();  //TODO Don't fire every frame, limit fire rate
	}
	
}