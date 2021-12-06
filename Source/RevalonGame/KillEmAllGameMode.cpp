// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"
void AKillEmAllGameMode::PawnKilled(APawn* ThePawn)
{
	if (Cast<APlayerController>(ThePawn->GetController()))
	{
		EndGame(false);
	}
	//for loop over all shooter AI in World
		//is not dead?
			//early return
	//end game
	for (AShooterAIController* Shooter : TActorRange<AShooterAIController>(GetWorld()))
	{
		if (!Shooter->isDead())
		{
			return;
		}
	}
	EndGame(true);
}

void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{
	for (AController* Controller : TActorRange<AController>(GetWorld()))
	{
		bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
	}
}
