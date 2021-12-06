// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RevalonGameGameModeBase.h"
#include "KillEmAllGameMode.generated.h"

/**
 * 
 */
UCLASS()
class REVALONGAME_API AKillEmAllGameMode : public ARevalonGameGameModeBase
{
	GENERATED_BODY()
public:
    virtual void PawnKilled(APawn* ThePawn) override;
};
