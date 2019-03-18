// Fill out your copyright notice in the Description page of Project Settings.

#include "RayTraceTestComponent.h"

// Sets default values for this component's properties
URayTraceTestComponent::URayTraceTestComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RTTMesh"));


	// ...
}


// Called when the game starts
void URayTraceTestComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URayTraceTestComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	FHitResult outHit;
	FVector startVector = mesh->GetComponentLocation();

	//FVector forwardVector = 

}

