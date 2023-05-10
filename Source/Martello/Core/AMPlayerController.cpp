#include "AMPlayerController.h"

void AMPlayerController::BeginPlay() {

	Super::BeginPlay();

	SetShowMouseCursor(true);

	DefaultCameraLocation = GetPawn()->GetActorLocation();
	DefaultCameraRotation = GetPawn()->GetActorRotation();
}

void AMPlayerController::ForwardPressed()
{
	b_MoveForward = true;
}

void AMPlayerController::BackPressed()
{
	b_MoveBack = true;
}

void AMPlayerController::LeftPressed()
{
	b_MoveLeft = true;
}

void AMPlayerController::RightPressed()
{
	b_MoveRight = true;
}

void AMPlayerController::ForwardReleased()
{
	b_MoveForward = false;
}

void AMPlayerController::BackReleased()
{
	b_MoveBack = false;
}

void AMPlayerController::LeftReleased()
{
	b_MoveLeft = false;
}

void AMPlayerController::RightReleased()
{
	b_MoveRight = false;
}

void AMPlayerController::RotateLeftPressed()
{
	b_RotateLeft = true;
}

void AMPlayerController::RotateLeftReleased()
{
	b_RotateLeft = false;
}

void AMPlayerController::RotateRightPressed()
{
	b_RotateRight = true;
}

void AMPlayerController::RotateRightReleased()
{
	b_RotateRight = false;
}

void AMPlayerController::ResetCameraLocation()
{
	if (APawn* ActorPawn = GetPawn())
	{
		ActorPawn->SetActorLocation(DefaultCameraLocation);
		ActorPawn->SetActorRotation(DefaultCameraRotation);
	}
}

void AMPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("CAMERA_BACK", IE_Pressed, this, &AMPlayerController::BackPressed);
	InputComponent->BindAction("CAMERA_BACK", IE_Released, this, &AMPlayerController::BackReleased);

	InputComponent->BindAction("CAMERA_FORWARD", IE_Pressed, this, &AMPlayerController::ForwardPressed);
	InputComponent->BindAction("CAMERA_FORWARD", IE_Released, this, &AMPlayerController::ForwardReleased);

	InputComponent->BindAction("CAMERA_RIGHT", IE_Pressed, this, &AMPlayerController::RightPressed);
	InputComponent->BindAction("CAMERA_RIGHT", IE_Released, this, &AMPlayerController::RightReleased);


	InputComponent->BindAction("CAMERA_LEFT", IE_Pressed, this, &AMPlayerController::LeftPressed);
	InputComponent->BindAction("CAMERA_LEFT", IE_Released, this, &AMPlayerController::LeftReleased);

	InputComponent->BindAction("CAMERA_ROTATE_LEFT", IE_Pressed, this, &AMPlayerController::RotateLeftPressed);
	InputComponent->BindAction("CAMERA_ROTATE_LEFT", IE_Released, this, &AMPlayerController::RotateLeftReleased);

	InputComponent->BindAction("CAMERA_ROTATE_RIGHT", IE_Pressed, this, &AMPlayerController::RotateRightPressed);
	InputComponent->BindAction("CAMERA_ROTATE_RIGHT", IE_Released, this, &AMPlayerController::RotateRightReleased);

	InputComponent->BindAction("RESET_CAMERA", IE_Pressed, this, &AMPlayerController::ResetCameraLocation);
}

void AMPlayerController::TickActor(float DeltaSeconds, ELevelTick TickType, FActorTickFunction& ThisTickFunction)
{
	Super::TickActor(DeltaSeconds, TickType, ThisTickFunction);

	if (APawn* ActorPawn = GetPawn()) 
	{
		FVector StartLocation = ActorPawn->GetActorLocation();
		FRotator StartRotation = ActorPawn->GetActorRotation();

		if (b_MoveBack) {
			StartLocation.X -= ForwardSpeed;
		}

		if (b_MoveForward) {
			StartLocation.X += ForwardSpeed;
		}

		if (b_MoveLeft) {
			StartLocation.Y -= SideSpeed;
		}

		if (b_MoveRight) {
			StartLocation.Y += SideSpeed;
		}

		if (b_RotateRight) {
			StartRotation.Yaw -= RotationSpeed;
		}

		if (b_RotateLeft) {
			StartRotation.Yaw += RotationSpeed;
		}

		ActorPawn->SetActorLocation(StartLocation);
		ActorPawn->SetActorRotation(StartRotation);
	}
}