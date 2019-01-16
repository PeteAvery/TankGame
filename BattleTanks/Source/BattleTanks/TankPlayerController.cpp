// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"



ATank* ATankPlayerController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());

}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	




	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) { 
		UE_LOG(LogTemp, Warning, TEXT("No Possossion") )
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s"), *ControlledTank->GetName())
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
	 //Aim towards crosshair
	AimTowardsCrosshair();


}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation; //OUT perameter
	if (GetSightRayHitLocation(HitLocation)) //This has a side effect. It will actually LineTrace
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *HitLocation.ToString())
			
			
				//TODO tell controlled tank to aim at this point
	}

}
//get world location if linetrace through crosshair, true if hits landscape.
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	return true;

}