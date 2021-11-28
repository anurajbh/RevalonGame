// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BehaviorTree.h"
void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();
	if (EnemyBehaviourTree)
	{
		RunBehaviorTree(EnemyBehaviourTree);
	}
	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	//SetFocus(PlayerPawn);
}
//void AShooterAIController::HandleEnemyMovement()
//{
//	if (LineOfSightTo(PlayerPawn))
//	{
//		SetFocus(PlayerPawn);
//		MoveToActor(PlayerPawn, AcceptanceRadius);
//	}
//	else
//	{
//		ClearFocus(EAIFocusPriority::Gameplay);
//		StopMovement();
//	}
//}
void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//HandleEnemyMovement();
}