// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup.h"
// TODO: Define in a file
#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)

// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create Mesh and sphere comp
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	collisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Collision Sphere"));

	collisionSphere->InitSphereRadius(100.0f);
	PickupMesh->SetSimulatePhysics(false);

	RootComponent = collisionSphere;
	PickupMesh->AttachTo(RootComponent);

	//isActive = true;

	// Enable collision
	SetActorEnableCollision(true);
	collisionSphere->SetGenerateOverlapEvents(true);
	PickupMesh->SetGenerateOverlapEvents(false);
	// Assign events to functions
	collisionSphere->OnComponentBeginOverlap.AddDynamic(this, &APickup::OnOverlapBegin);
	collisionSphere->OnComponentEndOverlap.AddDynamic(this, &APickup::OnOverlapEnd);
	collisionSphere->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
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
	this->Destroy(); // TODO: remove this !
}
void APickup::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, 
	AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	print("Overlap called");
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		CollectedImplementation();
	}
}
void APickup::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, 
	class AActor* OtherActor, 
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// Increase score or else. Do sth when overlap ends.
}