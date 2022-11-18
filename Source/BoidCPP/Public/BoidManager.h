
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Boid.h"
#include "BoidManager.generated.h"

UCLASS()
class BOIDCPP_API ABoidManager : public AActor
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		int numberOfBoids = 1500;
		UPROPERTY(EditAnywhere)
		FVector frame = FVector(1000, 1000, 1000);
		UPROPERTY(EditAnywhere)
		float rule1 = 5000;
		UPROPERTY(EditAnywhere)
		float rule2 = 120;
		UPROPERTY(EditAnywhere)
		float rule3 = 120;
		UPROPERTY(EditAnywhere)
		float distance = 30;
		UPROPERTY(EditAnywhere)
		float maxSpeed = 5;
		UPROPERTY(EditAnywhere)
		float ruleBorder = 1;
		UPROPERTY(EditAnywhere)
		float bounceBorder = 10;

	
public:	
	// Sets default values for this actor's properties
	ABoidManager();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	TArray<ABoid*> *boids;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//virtual FVector Rule1(ABoid* bj);
	//virtual FVector Rule2(ABoid* bj);
	//virtual FVector Rule3(ABoid* bj);
	//virtual FVector Border(ABoid* bj);
	//virtual void LimitSpeed(ABoid* b);
};
