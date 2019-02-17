// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "CoinPickup.generated.h"

/**
 * 
 */
UCLASS()
class DRIVESIM_API ACoinPickup : public APickup
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACoinPickup();
	//void CollectedImplementation() override;
};
