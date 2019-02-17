// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Classes/Components/SphereComponent.h"
#include "Pickup.generated.h" // Include generated must be the last include

UCLASS()
class DRIVESIM_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();


	// Returns if pickup is active
	UFUNCTION(BlueprintPure, Category = "Pickup")
	bool IsActive();
	// Sets pickup active state
	UFUNCTION(BlueprintCallable, Category = "Pickup")
	void SetActive(bool activeState);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	bool isActive;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Returns mesh for the pickup
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh; }

	// Function called on object when collected
	UFUNCTION(BluePrintNativeEvent)
	void Collected();
	virtual void CollectedImplementation();

	UPROPERTY(VisibleAnywhere, Category = "Pickup")
	class USphereComponent* collisionSphere;

	UFUNCTION()
		void OnOverlapBegin(class AActor* OtherActor, 
			class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
			bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapEnd(class AActor* OtherActor, 
			class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);



private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* PickupMesh;
};
