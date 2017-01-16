// Fill out your copyright notice in the Description page of Project Settings.

#include "VRInteractables.h"
#include "InteractableLever.h"


// Sets default values
AInteractableLever::AInteractableLever()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInteractableLever::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractableLever::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

