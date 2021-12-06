// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"

/**
 * 
 */
UCLASS()
class REVALONGAME_API AShooterAIController : public AAIController
{
	GENERATED_BODY()
protected:
		virtual void BeginPlay() override;
private:
	//UPROPERTY(EditAnywhere)
	//	float AcceptanceRadius = 200.f;
	UPROPERTY(EditAnywhere)
		class UBehaviorTree* EnemyBehaviourTree;
public:
	bool isDead() const;
};
