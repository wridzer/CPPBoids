// Fill out your copyright notice in the Description page of Project Settings.


#include "BoidManager.h"

// Sets default values
ABoidManager::ABoidManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	boids = new TArray<ABoid*>();
}

// Called when the game starts or when spawned
void ABoidManager::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0; i < numberOfBoids; i++)
	{
		FVector spawnPos = FVector(FMath::RandRange(0.0, frame.X), FMath::RandRange(0.0, frame.Y), FMath::RandRange(0.0, frame.Z));
		FActorSpawnParameters SpawnInfo;
		FRotator myRot(0, 0, 0);
		ABoid* boid = GetWorld()->SpawnActor<ABoid>(spawnPos, myRot, SpawnInfo);
		boid->position = spawnPos;
		boids->Add(boid);

		boid->boids = boids;
		boid->frame = frame;
		boid->rule1	= rule1;
		boid->rule2	= rule2;
		boid->rule3	= rule3;
		boid->distance = distance;
		boid->maxSpeed = maxSpeed;
		boid->ruleBorder = ruleBorder;
		boid->bounceBorder = bounceBorder;
	}
}

// Called every frame
void ABoidManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*FVector v1, v2, v3, v4;

	for (auto b : *boids)
	{
		v1 = Rule1(b);
		v2 = Rule2(b);
		v3 = Rule3(b);
		v4 = Border(b);

		b->velocity = b->velocity + v1 + v2 + v3 + v4;
		LimitSpeed(b);
		b->position = b->position + b->velocity;
	}*/

}

/*void ABoidManager::LimitSpeed(ABoid* bj)
{
	if (bj->velocity.Length() > maxSpeed)
	{
		bj->velocity = (bj->velocity / bj->velocity.Length()) * maxSpeed;
	}
}

FVector ABoidManager::Rule1(ABoid* bj)
{
	FVector pcj = FVector(0, 0, 0);

	for (auto b : *boids)
	{
		if (b != bj)
		{
			pcj = pcj + b->position;
		}
	}

	pcj = pcj / (boids->Num() - 1);

	return (pcj - bj->position) / rule1;
}

FVector ABoidManager::Rule2(ABoid* bj)
{
	FVector c = FVector(0, 0, 0);

	for (auto b : *boids)
	{
		if (b != bj)
		{
			if ((b->position - bj->position).Length() < distance)
			{
				c = c - (b->position - bj->position);
			}
		}
	}

	return c / rule2;
}

FVector ABoidManager::Rule3(ABoid* bj)
{
	FVector pvj = FVector(0, 0, 0);

	for (auto b : *boids)
	{
		if (b != bj)
		{
			pvj = pvj + b->velocity;
		}
	}

	pvj = pvj / (boids->Num() - 1);

	return (pvj - bj->velocity) / rule3;
}

FVector ABoidManager::Border(ABoid* bj)
{
	FVector v = FVector(0, 0, 0);

	if (bj->position.X < 0)
	{
		v.X = bounceBorder;
	}
	else if (bj->position.X > frame.X)
	{
		v.X = -bounceBorder;
	}

	if (bj->position.Y < 0)
	{
		v.Y = bounceBorder;
	}
	else if (bj->position.Y > frame.Y)
	{
		v.Y = -bounceBorder;
	}

	if (bj->position.Z < 0)
	{
		v.Z = bounceBorder;
	}
	else if (bj->position.Z > frame.Z)
	{
		v.Z = -bounceBorder;
	}

	return v / ruleBorder;
}*/

