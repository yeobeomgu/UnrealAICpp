// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/InventoryComponent.h"

// Sets default values
AInventoryComponent::AInventoryComponent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInventoryComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

