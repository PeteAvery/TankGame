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

public:

	

	ATank* GetControlledTank() const;

	

protected:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	
};
