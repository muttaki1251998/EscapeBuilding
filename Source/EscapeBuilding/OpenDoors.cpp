// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoors.h"
#include "Gameframework/Actor.h"
#include "Engine.h"		//For Get World

// Sets default values for this component's properties
UOpenDoors::UOpenDoors()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoors::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();		// Making Owner a global var

	Player = GetWorld()->GetFirstPlayerController()->GetPawn();	
	
}

void UOpenDoors::OpenDoor()
{
	Owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));
}

void UOpenDoors::CloseDoor()
{
	Owner->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
}


// Called every frame
void UOpenDoors::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PressurePlate->IsOverlappingActor(Player))
	{
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}

	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay)
	{
		CloseDoor();
	}
}

