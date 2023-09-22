// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAgent.h"

// Sets default values
AMyAgent::AMyAgent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void AMyAgent::BeginPlay()
{
	Super::BeginPlay();

	// GEngine->AddOnScreenDebugMessage(0, 3.0f, FColor::Red, FString::Printf(TEXT("%f"), InitLocation.X));
}

// Called every frame
void AMyAgent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector StartLocation = GetActorLocation();
	StartLocation.X += 5.f;
	
	SetActorLocation(StartLocation);
	
	GEngine->AddOnScreenDebugMessage(0, 3.0f, FColor::Cyan, FString::Printf(TEXT("%f"), StartLocation.X));
	
}

