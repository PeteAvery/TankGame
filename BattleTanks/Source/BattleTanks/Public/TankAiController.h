// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"

#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "AIController.h"
#include "TankAiController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankAiController : public AAIController
{
	GENERATED_BODY()

public:

	ATank* GetControlledTank() const;

	ATank* GetPlayerTank() const;

protected:

	virtual void BeginPlay() override;
	
};
