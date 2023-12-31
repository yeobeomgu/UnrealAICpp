// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TPDataTableManager.h"
#include "InventorySystemComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TEAMPROJECT_API UInventorySystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventorySystemComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	int32 InventorySize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	TArray<FST_Slot> Content;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	float InteractionRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor References")
	class AActor* LookAtActor;




protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
