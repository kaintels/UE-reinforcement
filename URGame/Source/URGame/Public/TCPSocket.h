// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TcpSocketConnection.h"
#include "TCPSocket.generated.h"

UCLASS()
class URGAME_API ATCPSocket : public ATcpSocketConnection
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATCPSocket();

	UFUNCTION()
		void OnConnected(int32 ConnectionId);
	UFUNCTION()
		void OnDisConnected(int32 ConId);
	UFUNCTION()
		void OnMessageReceived(int32 ConId, TArray<uint8>& Message);
	UFUNCTION(BlueprintCallable)
		void ConnectToGameServer();
	UPROPERTY()
		int32 ConnectionIdGameServer;
private:
	virtual void BeginPlay() override;
	
};


