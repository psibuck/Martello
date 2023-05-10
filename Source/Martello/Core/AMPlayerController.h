 #pragma once

#include "GameFramework/PlayerController.h"

#include "AMPlayerController.generated.h"

UCLASS()
class AMPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;
	virtual void TickActor(float DeltaSeconds, ELevelTick TickType, FActorTickFunction& ThisTickFunction) override;

	void ForwardPressed();
	void BackPressed();
	void LeftPressed();
	void RightPressed();
	void ForwardReleased();
	void BackReleased();
	void LeftReleased();
	void RightReleased();
	void RotateLeftPressed();
	void RotateLeftReleased();
	void RotateRightPressed();
	void RotateRightReleased();
	void ResetCameraLocation();

	void SetupInputComponent();

	UPROPERTY(EditDefaultsOnly)
	float SideSpeed = 10.0f;

	UPROPERTY(EditDefaultsOnly)
	float ForwardSpeed = 10.0f;

	UPROPERTY(EditDefaultsOnly)
	float RotationSpeed = 2.0f;

	bool b_MoveBack = false;
	bool b_MoveForward = false;
	bool b_MoveLeft = false;
	bool b_MoveRight = false;
	bool b_RotateLeft = false;
	bool b_RotateRight = false;

	FVector DefaultCameraLocation;
	FRotator DefaultCameraRotation;
};