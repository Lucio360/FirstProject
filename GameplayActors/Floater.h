// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Floater.generated.h"

UCLASS()
class FIRSTPROJECT_API AFloater : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloater();

	

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ActorMeshComponents")
	UStaticMeshComponent* StaticMesh;

	//Location use by SetActorLocation() when BeginPlay() is called
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "FloaterVariables")
	FVector InitialLocation;

	// Location of the actor when dragged in from the editor
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "FloaterVariables")
	FVector PlacedLocation;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "FloaterVariables")
	FVector WorldOrigin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FloaterVariables")
	FVector InitialDirection;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FloaterVariables")
	bool bShouldFloat;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "FloaterVariables")
	bool bInitializeFloaterLocations;

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "FloaterVariables")
	FVector InitialForce;

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "FloaterVariables")
	FVector InitialTorque;

private:

	float RunningTime;

	float BaseZLocation;

	//Amplitude - how much we oscilate up and down
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FloaterVariables", meta = (AllowPrivateAccess = "true"))
	float A;

	//Period = 2 * PI / (absolute value of B)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FloaterVariables", meta = (AllowPrivateAccess = "true"))
	float B;

	//Phase Shift is (C / B)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FloaterVariables", meta = (AllowPrivateAccess = "true"))
	float C;

	//Vertical Shift is D
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FloaterVariables", meta = (AllowPrivateAccess = "true"))
	float D;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
