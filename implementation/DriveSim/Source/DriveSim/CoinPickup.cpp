// Fill out your copyright notice in the Description page of Project Settings.

#include "CoinPickup.h"
#include "Pickup.h"
#include "Classes/Components/StaticMeshComponent.h"

// Set Defaults
ACoinPickup::ACoinPickup()
{
	UStaticMeshComponent* mesh = this->GetMesh(); // Disable physics on coin so it hangs in air
	mesh->SetSimulatePhysics(false);

}
/*void ACoinPickup::Collected_implementation()
{
	// call parent to log
	Super::Collected_implementation();
	Destroy();
}*/