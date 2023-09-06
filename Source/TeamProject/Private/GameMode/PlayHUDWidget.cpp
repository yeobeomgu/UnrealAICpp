// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/PlayHUDWidget.h"
#include "InventoryWidget.h"


void UPlayHUDWidget::OpenInven()
{
	InvenWidget->SetVisibility(ESlateVisibility::Visible);
	InvenWidget->OpenInven();
}

void UPlayHUDWidget::CloseInven()
{
	InvenWidget->SetVisibility(ESlateVisibility::Collapsed);
	InvenWidget->CloseInven();
}
