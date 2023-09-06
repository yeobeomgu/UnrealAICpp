// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/InventoryWidget.h"
#include "Kismet/GameplayStatics.h"
#include "JH/JHPlayerController.h"
#include "InventorySystemComponent.h"

UInventoryWidget::UInventoryWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// ���߿� TPController �� �ٲ�� ��
	AJHPlayerController* jhcontroller = Cast<AJHPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (jhcontroller != nullptr)
	{
		UInventorySystemComponent* invencomponent = jhcontroller->GetComponentByClass<UInventorySystemComponent>();
	}
}

void UInventoryWidget::OpenInven()
{
	// ���� �Ǿ� �ִµ�
}

void UInventoryWidget::CloseInven()
{
	// �̰͵� �����εǾ� �ִµ�
}
