// Fill out your copyright notice in the Description page of Project Settings.


#include "ClearBlackboardValue.h"
#include "BehaviorTree/BlackboardComponent.h"
UClearBlackboardValue ::UClearBlackboardValue()
{
	NodeName = TEXT("ClearBlackBoardValue");
}

EBTNodeResult::Type UClearBlackboardValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	return EBTNodeResult::Succeeded;
}
