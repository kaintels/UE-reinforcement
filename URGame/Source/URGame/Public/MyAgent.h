// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyAgent.generated.h"

UCLASS()
class URGAME_API AMyAgent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyAgent();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="MoveActor")
	float Speed = 5.f;
	UPROPERTY(VisibleAnywhere)
	FVector Initlocation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
