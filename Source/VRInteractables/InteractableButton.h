// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "InteractableButton.generated.h"

UCLASS()
class VRINTERACTABLES_API AInteractableButton : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractableButton();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess), Category = "Mesh")
		class USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess), Category = "Mesh")
		class UStaticMeshComponent* PushableButtonMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* ButtonBaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UPhysicsConstraintComponent* ButtonSpringConstraint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ButtonTriggerDistance;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool bIsButtonPushed;

	UFUNCTION(BlueprintImplementableEvent, Category = "Button")
		void OnButtonPushed();

	UFUNCTION(BlueprintImplementableEvent, Category = "Button")
		void OnButtonReleased();

};
