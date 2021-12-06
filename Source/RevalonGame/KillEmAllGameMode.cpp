// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"
void AKillEmAllGameMode::PawnKilled(APawn* ThePawn)
{
	APlayerController* PlayerController = Cast<APlayerController>(ThePawn->GetController());
	if (PlayerController)
	{
		PlayerController->GameHasEnded();
	}
}
