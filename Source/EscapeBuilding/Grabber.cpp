// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"

// Sets default values
AGrabber::AGrabber()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGrabber::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGrabber::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

