// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Projectile.generated.h"

class UProjectileMovementComponent;

UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();
	void LaunchProjectile(float speed);

//	UFUNCTION(BlueprintCallable, Category = "Setup")
//	void Initialise(UStaticMeshComponent* CollisionMeshToSet, UParticleSystemComponent* LaunchBlastToSet);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UProjectileMovementComponent* ProjectileMovementComponent = nullptr;
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	UStaticMeshComponent* CollisionMesh = nullptr;
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	UParticleSystemComponent* LaunchBlast = nullptr;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



};
