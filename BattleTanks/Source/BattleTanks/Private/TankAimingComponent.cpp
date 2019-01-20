// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{

	Barrel = BarrelToSet;

}



void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed) 
{
	
	if (!Barrel) { return; }



	FVector LaunchVelocity;
	FVector LaunchLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		LaunchVelocity,
		LaunchLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0.0f, //as we are using the default values for these 3 parameters, we could just not put them in.
		0.0f,
		ESuggestProjVelocityTraceOption::DoNotTrace);

	if (bHaveAimSolution)
	{
		
		auto AimDirection = LaunchVelocity.GetSafeNormal();
		// UE_LOG(LogTemp, Warning, TEXT("Firing at Velocity : %s"), *AimDirection.ToString())
		 MoveBarrelTowards(AimDirection);
	}

}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) const
{

	//Work out difference between current barrel rotation and AimDirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = (AimAsRotator - BarrelRotator);
	//Move the barrel the right amount this frame

	//Given a max elevation time, and frame time

}
