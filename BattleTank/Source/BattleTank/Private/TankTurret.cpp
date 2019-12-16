// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::Rotate(float RotateSpeed)
{
	auto ClampedRotateSpeed = FMath::Clamp<float>(RotateSpeed, -1, 1);
	auto RotationChange = ClampedRotateSpeed * TurnSpeed * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}

