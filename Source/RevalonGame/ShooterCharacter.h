// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

UCLASS()
class REVALONGAME_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly)
		float MaxHealth = 100.f;

public:	
	UFUNCTION(BlueprintPure)
		bool hasDied() const;
	UFUNCTION(BlueprintPure)
		float GetHealth() const;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	void Shoot();
private :
	void MoveForward(float AxisInput);
	void MoveRight(float AxisInput);
	UPROPERTY(EditAnywhere)
		float RotationRate = 10.f;
	class AGun* GunPtr = nullptr;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AGun> GunClass;
	void LookUpRate(float AxisInput);
	void LookRightRate(float AxisInput);
	UPROPERTY(VisibleAnywhere)
		float CurrentHealth = 100.f;
	//void ShooterJump();
};
