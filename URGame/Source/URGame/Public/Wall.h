// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "Wall.generated.h"

/**
 * 
 */
UCLASS()
class URGAME_API AWall : public ATriggerVolume
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
public:
	AWall();

	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	UFUNCTION()
	void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);
	
};
