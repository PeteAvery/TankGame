// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"


ATank* ATankAiController::GetControlledTank() const
{


	return Cast<ATank>(GetPawn());

}

ATank* ATankAiController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) { return nullptr;  }
	else {
		return Cast<ATank>(PlayerTank);
	}
}

void ATankAiController::BeginPlay()

{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ai controller can't find player tank!"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player tank - %s"), *PlayerTank->GetName())

	}



}

void ATankAiController::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

	if (GetControlledTank())
	{

		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

	}
	//Aim towards crosshair
	//AimTowardsCrosshair();


}




