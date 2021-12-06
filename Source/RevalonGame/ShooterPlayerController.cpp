// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"
void AShooterPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);
	HUDScreen->RemoveFromViewport();
	if (bIsWinner)
	{
		UUserWidget* WinScreen = CreateWidget(this, WinScreenWidget);
		if (WinScreen)
		{
			WinScreen->AddToViewport();
		}
	}
	else
	{
		UUserWidget* LoseScreen = CreateWidget(this, LoseScreenWidget);
		if (LoseScreen)
		{
			LoseScreen->AddToViewport();
		}
	}
	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}

void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();
	HUDScreen = CreateWidget(this, HUDWidget);
	if (HUDScreen)
	{
		HUDScreen->AddToViewport();
	}
}
