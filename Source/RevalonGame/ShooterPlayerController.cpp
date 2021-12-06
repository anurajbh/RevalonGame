// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
void AShooterPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);
	UE_LOG(LogTemp, Warning, TEXT("Game has ended"));
	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}
