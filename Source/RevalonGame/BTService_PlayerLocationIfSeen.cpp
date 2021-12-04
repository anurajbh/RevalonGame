// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocationIfSeen.h"
#include "ShooterAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
void UBTService_PlayerLocationIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	AAIController* OwnerAIController = OwnerComp.GetAIOwner();
	if (!OwnerAIController)
	{
		return;
	}
	UBlackboardComponent* OwnerBBComponent = OwnerComp.GetBlackboardComponent();
	if (!OwnerBBComponent)
	{
		return;
	}
	if (OwnerAIController->LineOfSightTo(PlayerPawn))
	{
		OwnerBBComponent->SetValueAsVector(GetSelectedBlackboardKey(), PlayerPawn->GetActorLocation());
	}
	else
	{
		OwnerBBComponent->ClearValue(GetSelectedBlackboardKey());
	}
}
UBTService_PlayerLocationIfSeen ::UBTService_PlayerLocationIfSeen()
{
	NodeName = TEXT("UpdatePlayerLocationIfSeen");
}

