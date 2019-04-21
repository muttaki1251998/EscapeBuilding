// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoors.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEBUILDING_API UOpenDoors : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoors();

private:
	UPROPERTY(EditAnywhere)
		float OpenAngle = -90.0f;

	UPROPERTY(EditAnywhere)
		ATriggerVolume *PressurePlate;

	UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 1.0f;
		
	float LastDoorOpenTime;
		

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();

	void CloseDoor();

	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	AActor *Player;
	AActor *Owner;	// The door itself that will close by itself
};
