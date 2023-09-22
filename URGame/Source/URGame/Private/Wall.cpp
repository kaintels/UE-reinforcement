// Fill out your copyright notice in the Description page of Project Settings.


#include "Wall.h"
#include "MyAgent.h"

AWall::AWall()
{
	//Register Events
	OnActorBeginOverlap.AddDynamic(this, &AWall::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AWall::OnOverlapEnd);


}

// Called when the game starts or when spawned
void AWall::BeginPlay()
{
	Super::BeginPlay();

	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, 999, 0, 5);
}

void AWall::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	// check if Actors do not equal nullptr and that 
	if (OtherActor && OtherActor != this) 
	{
		if (GEngine) 
		{
			
			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Begin"));
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("Overlapped Actor = %s"), *OverlappedActor->GetName()));

			UClass* MyAgentUClass = AMyAgent::StaticClass();
			AMyAgent* MyAgent = MyAgentUClass->GetDefaultObject<AMyAgent>();

			FVector MyAgentLoc = MyAgent->Initlocation;

			OtherActor->SetActorLocation(MyAgentLoc);
			
		}
	}
}

void AWall::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (OtherActor && OtherActor != this) 
	{
		if (GEngine) 
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Ended"));
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("%s has left the Trigger Box"), *OtherActor->GetName()));
			
		}
	}
}