// Fill out your copyright notice in the Description page of Project Settings.


#include "BG/BTTask_ClearBlackboardValue.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_ClearBlackboardValue::UBTTask_ClearBlackboardValue()
{
	NodeName = "Clear Blackboard Value";
}

EBTNodeResult::Type UBTTask_ClearBlackboardValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	//BlackboardKey�� FName�� ��ȯ�Ѵ�.
	//GetSelectedBlackboardKey();
	OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());

	//Succeeded�� ��ȯ�Ѵ�.
	return EBTNodeResult::Succeeded;
}