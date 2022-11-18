// Fill out your copyright notice in the Description page of Project Settings.


#include "Boid.h"
#include <Kismet/KismetMathLibrary.h>

// Sets default values
ABoid::ABoid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> VisualAsset(TEXT("StaticMesh'/Game/bijinblender.bijinblender'"));


	if (VisualAsset.Object)
	{
		VisualMesh->SetStaticMesh(VisualAsset.Object);
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

	FRotator PlayerRot = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), GetActorLocation() + velocity);
	
	PlayerRot = PlayerRot + FRotator(0.0, 90.0, 0.0);
	FRotator NewRot = FMath::RInterpTo(GetActorRotation(), PlayerRot, DeltaTime, 5);
	SetActorRotation(NewRot);


	SetActorLocation(position);
}

