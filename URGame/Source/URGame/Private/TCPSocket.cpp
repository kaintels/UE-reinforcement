// Fill out your copyright notice in the Description page of Project Settings.


#include "TCPSocket.h"

#include "WorldPartition/ContentBundle/ContentBundleLog.h"

// Sets default values
ATCPSocket::ATCPSocket()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATCPSocket::OnConnected(int32 ConnectionId)
{
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Cyan, TEXT("Log: Connected to server."));
}

void ATCPSocket::OnDisConnected(int32 ConId)
{
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Cyan, TEXT("Log: OnDisconnected."));
}

void ATCPSocket::OnMessageReceived(int32 ConId, TArray<uint8>& Message)
{


	if (Message.Num() !=0)
	{
		FString MessageVal = Message_ReadString(Message, Message.Num());
		GEngine->AddOnScreenDebugMessage(0, 3.0f, FColor::Cyan, TEXT("Log: Received message."));
		GEngine->AddOnScreenDebugMessage(1, 3.0f, FColor::Cyan, FString::Printf(TEXT("%s"), *MessageVal));
	}
	
}

void ATCPSocket::ConnectToGameServer()
{
		if (isConnected(ConnectionIdGameServer))
    	{
			GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Cyan, TEXT("Log: Can't connect SECOND time. We're already connected!"));
    		return;
    	}
    	FTcpSocketDisconnectDelegate disconnectDelegate;
    	disconnectDelegate.BindDynamic(this, &ATCPSocket::OnDisConnected);
    	FTcpSocketConnectDelegate connectDelegate;
    	connectDelegate.BindDynamic(this, &ATCPSocket::OnConnected);
    	FTcpSocketReceivedMessageDelegate receivedDelegate;
    	receivedDelegate.BindDynamic(this, &ATCPSocket::OnMessageReceived);
    	Connect("127.0.0.1", 8000, disconnectDelegate, connectDelegate, receivedDelegate, ConnectionIdGameServer);
}

void ATCPSocket::BeginPlay()
{
	ConnectToGameServer();
}

