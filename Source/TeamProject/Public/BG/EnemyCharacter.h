// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TeamProject.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"



UCLASS()
class TEAMPROJECT_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void PostInitializeComponents() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	void Attack();

	UFUNCTION()
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);
	
	void AttackStartComboState();
	void AttackEndComboState();

	void AttackCheck();

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack)
	bool IsAttacking;
	
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack)
	bool CanNextCombo;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack)
	bool IsComboInputOn;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack)
	int32 CurrentCombo;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack)
	int32 MaxCombo;
	
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack)
	float AttackRange;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack)
	float AttackRadius;

	UPROPERTY()
	class UEnemyAnimInstance* AttackAnim;


	


private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	


	UPROPERTY(EditAnywhere)
	float RotationRate = 10;

};
