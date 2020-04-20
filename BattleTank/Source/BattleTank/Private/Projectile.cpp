// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("CollisionMesh"));
	SetRootComponent(CollisionMesh);
	CollisionMesh->SetNotifyRigidBodyCollision(true);
	CollisionMesh->SetVisibility(true);

	LaunchBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("LaunchBlast"));
	LaunchBlast->AttachTo(RootComponent);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement"));
	ProjectileMovementComponent->bAutoActivate = false;
}

void AProjectile::LaunchProjectile(float Speed)
{
	UE_LOG(LogTemp, Warning, TEXT("Firing at %f"), Speed);
	ProjectileMovementComponent->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	ProjectileMovementComponent->Activate();
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
}

/*void AProjectile::Initialise(UStaticMeshComponent* CollisionMeshToSet, UParticleSystemComponent* LaunchBlastToSet)
{
	CollisionMesh = CollisionMeshToSet;
	LaunchBlast = LaunchBlastToSet;
}
*/
// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



