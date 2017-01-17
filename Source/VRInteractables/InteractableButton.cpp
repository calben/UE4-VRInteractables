// Fill out your copyright notice in the Description page of Project Settings.

#include "VRInteractables.h"
#include "InteractableButton.h"


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
	PushableButtonMesh->SetSimulatePhysics(true);
	PushableButtonMesh->GetBodyInstance()->bLockYTranslation = true;
	PushableButtonMesh->GetBodyInstance()->bLockZTranslation = true;
	PushableButtonMesh->GetBodyInstance()->bLockXRotation = true;
	PushableButtonMesh->GetBodyInstance()->bLockYRotation = true;
	PushableButtonMesh->GetBodyInstance()->bLockZRotation = true;
	PushableButtonMesh->GetBodyInstance()->SetDOFLock(EDOFMode::SixDOF);
}

// Called when the game starts or when spawned
void AInteractableButton::BeginPlay()
{
	Super::BeginPlay();
	ButtonConstraint.SetLinearPositionTarget(PushableButtonMesh->RelativeLocation);
	ButtonConstraint.SetLinearPositionDrive(true, true, true);
}

// Called every frame
void AInteractableButton::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	UE_LOG(LogTemp, Warning, TEXT("BUTTON LOCATION: %s"), *PushableButtonMesh->RelativeLocation.ToString());
	if (PushableButtonMesh->RelativeLocation.X < ButtonTriggerDistance)
	{
		if(bIsButtonPushed)
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
		if(bIsButtonPushed)
		{
			bIsButtonPushed = false;
			OnButtonReleased();
		}
		else
		{
			
		}
	}
}
