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
		GetControlledTank()->AimAt(HitLocation);
				//TODO tell controlled tank to aim at this point
	}

}
//get world location if linetrace through crosshair, true if hits landscape.
bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const
{
	
	//find the crosshair position
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	FVector2D ScreenLocation((ViewPortSizeX * CrossHairXLocation), (ViewPortSizeY * CrossHairYLocation));
	//I did the above... which worked. He did as follows : auto ScreenLocation = FVector2D(x,y)(as above)
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//FHitResult HitResult = GetLookVectorHitLocation(LookDirection);
		GetLookVectorHitLocation(LookDirection, HitLocation);
		//UE_LOG(LogTemp, Warning, TEXT("Look Direction : %s"), *LookDirection.ToString())
		
				}
		
	//Line-Trace along that look direction and see what we hit, up to a maximum range.
	return true;
}
														//IN parameter			OUT parameter
bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const
{
	FHitResult HitResult;
	//start location is CAMERA location
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + LookDirection * LineTraceRange;
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECC_Visibility)) {
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;

}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const
{
	//"De-Project" the screen position of the crosshair to a world position
	FVector WorldLocation; //This is not really required for what we need, but is required for the method below.
return	DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		WorldLocation,
		LookDirection); //lookdirection is defined in the brackets at the top of this method.
}

/*FHitResult ATankPlayerController::GetLookVectorHitLocation(FVector &LookDirection) const
{
	FHitResult Hit;
	 
	auto  PlayerTankLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	FVector LineTraceEnd = PlayerTankLocation + LookDirection * LineTraceRange;
	GetWorld()->LineTraceSingleByChannel
	(
		Hit,
		PlayerTankLocation,
		LineTraceEnd,
		ECC_Visibility
	);

	return Hit;

}*/ 