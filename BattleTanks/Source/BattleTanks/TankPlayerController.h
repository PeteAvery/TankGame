// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "tank.h"
#include "CoreMinimal.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	 UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5f;

	 UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.3333f;
	
	 ATank* GetControlledTank() const;

	 bool GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const;


public:

	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	

	

protected:

	

	
};
