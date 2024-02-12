// Fill out your copyright notice in the Description page of Project Settings.

#include "SoulsPlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Logging/LogMacros.h"

ASoulsPlayerController::ASoulsPlayerController()
{
}

void ASoulsPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(MappingContext, 0);
	}

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASoulsPlayerController::Move);
		EnhancedInputComponent->BindAction(LookAroundAction, ETriggerEvent::Triggered, this, &ASoulsPlayerController::LookAround);
	}
}

void ASoulsPlayerController::Move(const FInputActionValue& Value)
{
	const FVector2D MoveScaleValue = Value.Get<FVector2D>();

	// Get control direction
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	// Get FW vector
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	// Get Right vector 
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	GetPawn()->AddMovementInput(ForwardDirection, MoveScaleValue.Y);
	GetPawn()->AddMovementInput(RightDirection, MoveScaleValue.X);
}

void ASoulsPlayerController::LookAround(const FInputActionValue& Value)
{
	const FVector2D LookAroundScaleValue = Value.Get<FVector2D>();

	GetPawn()->AddControllerYawInput(LookAroundScaleValue.X);
	GetPawn()->AddControllerPitchInput(LookAroundScaleValue.Y);
}