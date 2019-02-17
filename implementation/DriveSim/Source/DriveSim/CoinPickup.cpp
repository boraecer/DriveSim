// Fill out your copyright notice in the Description page of Project Settings.

#include "CoinPickup.h"
//#include "Pickup.h"
//#include "Classes/Components/StaticMeshComponent.h"

// Set Defaults
ACoinPickup::ACoinPickup()
{
	UStaticMeshComponent* mesh = this->GetMesh(); // Disable physics on coin so it hangs in air
	mesh->SetSimulatePhysics(false);
	mesh->OnComponentBeginOverlap.AddDynamic(this, &ACoinPickup::OnOverlapBegin);

}
void ACoinPickup::CollectedImplementation()
{
	// call parent to log
	Super::CollectedImplementation();
	Destroy();
}
void ACoinPickup::OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		// Turn off the light  
		CollectedImplementation();
	}
}