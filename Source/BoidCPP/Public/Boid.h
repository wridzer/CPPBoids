// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Boid.generated.h"

UCLASS()
class BOIDCPP_API ABoid : public AActor
{
	GENERATED_BODY()
		UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* VisualMesh;

	
public:	
	// Sets default values for this actor's properties
	ABoid();

	FVector position;
	FVector velocity;

	FVector frame;
	float rule1;
	float rule2;
	float rule3;
	float distance;
	float maxSpeed;
	float ruleBorder;
	float bounceBorder;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	TArray<ABoid*>* boids;
};
