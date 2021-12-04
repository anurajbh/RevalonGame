// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();
	if (EnemyBehaviourTree)
	{
		RunBehaviorTree(EnemyBehaviourTree);
	}
	GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
}