// Fill out your copyright notice in the Description page of Project Settings.

#include "Bot_Character.h"
#include "GameFramework/CharacterMovementComponent.h "
#define EXPIRY_THRESHOLD 500

// Sets default values
ABot_Character::ABot_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
}

// Called when the game starts or when spawned
void ABot_Character::BeginPlay()
{
	Super::BeginPlay();
	expiryTimer = 0;
}

// Called every frame
void ABot_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	expiryTimer++;
	if (expiryTimer > EXPIRY_THRESHOLD) // Self destruct after a certain amount of time
		this->Destroy();
}

// Called to bind functionality to input
void ABot_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABot_Character::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{

}

void ABot_Character::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
}

void ABot_Character::CollidedWithVehicle()
{
	print("Overlap called on Bot");
	this->Destroy();
}

