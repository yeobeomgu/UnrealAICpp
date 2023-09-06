// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/InventoryWidget.h"
#include "Kismet/GameplayStatics.h"
#include "JH/JHPlayerController.h"
#include "InventorySystemComponent.h"

UInventoryWidget::UInventoryWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// 나중에 TPController 로 바꿔야 됨
	AJHPlayerController* jhcontroller = Cast<AJHPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (jhcontroller != nullptr)
	{
		UInventorySystemComponent* invencomponent = jhcontroller->GetComponentByClass<UInventorySystemComponent>();
	}
}

void UInventoryWidget::OpenInven()
{
	// 생성 되어 있는디
}

void UInventoryWidget::CloseInven()
{
	// 이것도 생성인되어 있는디
}
