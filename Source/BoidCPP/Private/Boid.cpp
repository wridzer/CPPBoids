// Fill out your copyright notice in the Description page of Project Settings.


#include "Boid.h"
#include <Kismet/KismetMathLibrary.h>

// Sets default values
ABoid::ABoid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone"));

	if (CubeVisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		VisualMesh->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));
	}

	//TArray<ABoid*>* &boids = new TArray<ABoid*>();
}

// Called when the game starts or when spawned
void ABoid::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator PlayerRot = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), GetActorLocation() + velocity);
	PlayerRot = PlayerRot + FRotator(-90.0, 0.0, 0.0);
	SetActorRotation(PlayerRot);

	FVector pcj = FVector(0, 0, 0);
	FVector c = FVector(0, 0, 0);
	FVector pvj = FVector(0, 0, 0);
	FVector border = FVector(0, 0, 0);

	for (auto b : *boids)
	{
		if (b != this)
		{
			pcj = pcj + b->position; // Rule 1

			// Rule 2
			if ((b->position - position).Length() < distance)
			{
				c = c - (b->position - position);
			}

			// Rule 3
			pvj = pvj + b->velocity;
		}
	}

	pcj = pcj / (boids->Num() - 1);
	pcj = (pcj - position) / rule1;

	c = c / rule2;

	pvj = pvj / (boids->Num() - 1);
	pvj = (pvj - velocity) / rule3;

	// Border Check
	if (position.X < 0)
	{
		border.X = bounceBorder;
	}
	else if (position.X > frame.X)
	{
		border.X = -bounceBorder;
	}

	if (position.Y < 0)
	{
		border.Y = bounceBorder;
	}
	else if (position.Y > frame.Y)
	{
		border.Y = -bounceBorder;
	}

	if (position.Z < 0)
	{
		border.Z = bounceBorder;
	}
	else if (position.Z > frame.Z)
	{
		border.Z = -bounceBorder;
	}
	border = border / ruleBorder;

	// Add rules, limit velocity and calculate new position
	velocity = velocity + pcj + c + pvj + border;
	if (velocity.Length() > maxSpeed)
	{
		velocity = (velocity / velocity.Length()) * maxSpeed;
	}	
	position = position + velocity;

	SetActorLocation(position);
}

