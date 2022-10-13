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

	//Vector3 lookDir = Vector3.RotateTowards(transform.forward, velocity.normalized, 5 * Time.deltaTime, 0f);
	//transform.rotation = Quaternion.LookRotation(lookDir);


	FRotator PlayerRot = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), GetActorLocation() + velocity);
	//FRotator NewRot = FMath::RInterpTo(GetActorRotation(), PlayerRot, DeltaTime, 200);
	PlayerRot = PlayerRot + FRotator(-90.0, 0.0, 0.0);
	SetActorRotation(PlayerRot);


	SetActorLocation(position);
}

