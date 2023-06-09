#include "TankPlayerController.h"
#include "TamkPawn.h"
#include "DrawDebugHelpers.h"

void ATankPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &ATankPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ATankPlayerController::MoveRight);
	InputComponent->BindAxis("RotateRight", this, &ATankPlayerController::RotateRight);
	InputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &ATankPlayerController::Fire);
	InputComponent->BindAction("FireSpecial", EInputEvent::IE_Pressed, this, &ATankPlayerController::FireSpecial);
}

void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	FVector MouseDirection;
	DeprojectMousePositionToWorld(MousePos, MouseDirection);
	FVector PawnPosition = TankPawn->GetActorLocation();
	MousePos.Z = PawnPosition.Z;
	FVector dir = MousePos - PawnPosition;
	dir.Normalize();
	MousePos = PawnPosition + dir * 1000;
	DrawDebugLine(GetWorld(), PawnPosition, MousePos, FColor::Green, false, 0.1f, 0, 5);
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	bShowMouseCursor = true;
	TankPawn = Cast<ATamkPawn>(GetPawn());
}

void ATankPlayerController::MoveForward(float Value)
{
	if (TankPawn)
	{
		TankPawn->MoveForward(Value);
	}
}

void ATankPlayerController::MoveRight(float Value)
{
	if (TankPawn)
	{
		TankPawn->MoveRight(Value);
	}
}

void ATankPlayerController::RotateRight(float Value)
{
	if (TankPawn)
	{
		TankPawn->RotateRight(Value);
	}
}

void ATankPlayerController::FireSpecial()
{
	if (TankPawn)
	{
		TankPawn->FireSpecial();
	}
}

void ATankPlayerController::Fire()
{
	if (TankPawn)
	{
		TankPawn->Fire();
	}
}
