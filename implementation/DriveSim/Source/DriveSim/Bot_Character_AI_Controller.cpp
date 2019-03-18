// Fill out your copyright notice in the Description page of Project Settings.

#include "Bot_Character_AI_Controller.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

ABot_Character_AI_Controller::ABot_Character_AI_Controller()
{
	PrimaryActorTick.bCanEverTick = true;
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent"));
	SetPerceptionComponent(*PerceptionComponent);

	SightConfig->SightRadius = AISightRadius;
	SightConfig->LoseSightRadius = AILoseSightRadius;
	SightConfig->PeripheralVisionAngleDegrees = AIFieldOfView;
	SightConfig->SetMaxAge(AISightAge);
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;

	GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
	GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &ABot_Character_AI_Controller::OnPawnDetected); // Call back to our function
	GetPerceptionComponent()->ConfigureSense(*SightConfig);
}
void ABot_Character_AI_Controller::BeginPlay()
{
	Super::BeginPlay();
}

void ABot_Character_AI_Controller::Possess(APawn * pawn)
{
	Super::Possess(pawn);
}

void ABot_Character_AI_Controller::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

FRotator ABot_Character_AI_Controller::GetControlRotation() const
{
	if (GetPawn() == NULL)
		return FRotator(0, 0, 0);
	return FRotator(0, GetPawn()->GetActorRotation().Yaw, 0);
}

void ABot_Character_AI_Controller::OnPawnDetected(TArray<AActor*> DetectedPawns)
{
	// Do nothing for now
}
