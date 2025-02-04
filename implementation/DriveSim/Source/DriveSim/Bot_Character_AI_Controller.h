// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Bot_Character_AI_Controller.generated.h"
#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)

/**
 * 
 */
UCLASS()
class DRIVESIM_API ABot_Character_AI_Controller : public AAIController
{
	GENERATED_BODY()
	

public:
	ABot_Character_AI_Controller();

	virtual void BeginPlay() override;
	virtual void Possess(APawn* pawn) override;
	virtual void Tick(float DeltaSeconds) override;
	virtual FRotator GetControlRotation() const override;

	UFUNCTION()
	void OnPawnDetected(TArray<AActor*> DetectedPawns);
	UFUNCTION(BlueprintCallable, Category = "Bot")
	FVector getMyPawnVector();
	UFUNCTION(BlueprintCallable, Category = "Bot")
	FVector getMyPawnLocation();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
		float AISightRadius = 500.0;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
		float AISightAge = 5.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
		float AILoseSightRadius = AISightRadius + 50;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
		float AIFieldOfView = 100;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
		class UAISenseConfig_Sight* SightConfig;

public:
	APawn* myPawn;
};
