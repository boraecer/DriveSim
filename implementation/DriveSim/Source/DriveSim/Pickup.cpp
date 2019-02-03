// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create Mesh comp
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	RootComponent = PickupMesh;
	isActive = true;
}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
bool APickup::IsActive()
{
	return this->isActive;
}
void APickup::SetActive(bool activeState)
{
	this->isActive = activeState;
}
/*void APickup::Collected()
{
	int x = 0;
}*/
/*void APickup::Collected_implementation()
{
	//FString dbStr = GetName();
	UE_LOG(LogClass, Log, TEXT("Collected "))//, *dbStr)
}*/