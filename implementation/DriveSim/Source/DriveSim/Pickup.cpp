// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup.h"


// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create Mesh comp
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	RootComponent = PickupMesh;
	isActive = true;

	// Enable collision
	SetActorEnableCollision(true);

	collisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Collision Sphere"));
	collisionSphere->InitSphereRadius(100);
	collisionSphere->SetupAttachment(RootComponent);

	//collisionSphere->OnComponentBeginOverlap.AddDynamic(this, &APickup::OnOverlapBegin);
	//collisionSphere->OnComponentEndOverlap.AddDynamic(this, &APickup::OnOverlapEnd);
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
void APickup::Collected()
{
	//
}
void APickup::CollectedImplementation()
{
	FString dbStr = GetName();
	UE_LOG(LogClass, Log, TEXT("Collected %s"), *dbStr);
}
void APickup::OnOverlapBegin(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		CollectedImplementation();
	}
}
void APickup::OnOverlapEnd(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// Increase score or else. Do sth when overlap ends.
}