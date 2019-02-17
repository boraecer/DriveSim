// Fill out your copyright notice in the Description page of Project Settings.

#include "CoinPickup.h"
//#include "Pickup.h"
//#include "Classes/Components/StaticMeshComponent.h"

// Set Defaults
ACoinPickup::ACoinPickup()
{
	UStaticMeshComponent* mesh = this->GetMesh(); // Disable physics on coin so it hangs in air
	mesh->SetSimulatePhysics(false);
	//mesh->OnComponentBeginOverlap.AddDynamic(this, &ACoinPickup::OnOverlapBegin);

}
/*void ACoinPickup::CollectedImplementation()
{
	// call parent to log
	Super::CollectedImplementation();
	Destroy();
}*/
