// Fill out your copyright notice in the Description page of Project Settings.

#include "VRInteractables.h"
#include "InteractableButton.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"


// Sets default values
AInteractableButton::AInteractableButton()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Scene;

	ButtonBaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ButtonBaseMesh"));
	ButtonBaseMesh->SetupAttachment(Scene);

	PushableButtonMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PushableButtonMesh"));
	PushableButtonMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AInteractableButton::BeginPlay()
{
	Super::BeginPlay();

	PushableButtonMesh->SetSimulatePhysics(true);
	PushableButtonMesh->SetEnableGravity(false);
}

// Called every frame
void AInteractableButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//PushableButtonMesh->SetWorldRotation(ButtonBaseMesh->GetComponentRotation());

	UE_LOG(LogTemp, Warning, TEXT("FVector Distance is %f"), FVector::Dist(PushableButtonMesh->GetComponentLocation(), ButtonBaseMesh->GetComponentLocation()));
	if (FVector::Dist(PushableButtonMesh->GetComponentLocation(), ButtonBaseMesh->GetComponentLocation()) < ButtonTriggerDistance)
	{
		if (bIsButtonPushed)
		{
			//
		}
		else
		{
			bIsButtonPushed = true;
			OnButtonPressed();
		}
	}
	else
	{
		if (bIsButtonPushed)
		{
			bIsButtonPushed = false;
			OnButtonReleased();
		}
		else
		{

		}
	}
}
