// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/PlayerController.h"
#include "SoulsBossFight/SoulsBossFightCharacter.h"
#include "SoulsPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class UCharacterMovementComponent;
class USpringArmComponent;
class ACharacter;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class SOULSBOSSFIGHT_API ASoulsPlayerController : public APlayerController
{
	GENERATED_BODY()

	// Properties
	// Mapping Inputs
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* MappingContext;

	// Input Actions
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAroundAction;

public: 
	// Constructor
	ASoulsPlayerController();

protected:
	// Functions
	UFUNCTION(BlueprintCallable)
	void Move(const FInputActionValue& Value);

	UFUNCTION(BlueprintCallable)
	void LookAround(const FInputActionValue& Value);

protected:
	virtual void BeginPlay();

//public:
	FORCEINLINE class UCharacterMovementComponent* GetCharacterMovementComponent() const { return Cast<ACharacter>(GetOwner())->GetCharacterMovement(); }

	FORCEINLINE class USpringArmComponent* GetSpringArmComponent() const { return Cast<ASoulsBossFightCharacter>(GetOwner())->GetCameraBoom(); }
};
