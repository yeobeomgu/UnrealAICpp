// Fill out your copyright notice in the Description page of Project Settings.


#include "BG/EnemyAnimInstance.h"

UEnemyAnimInstance::UEnemyAnimInstance()
{
	CurrentPawnSpeed = 0.0f;

	IsDead = false;

	static ConstructorHelpers::FObjectFinder<UAnimMontage>ATTACK_MONTAGE(TEXT("/Script/Engine.AnimMontage'/Game/BG/AssetPacks/ParagonWraith/Characters/Heroes/Wraith/Animations/Wraith_Skeleton_Montage.Wraith_Skeleton_Montage'"));
	if (ATTACK_MONTAGE.Succeeded())
	{
		UE_LOG(LogTemp, Display, TEXT("ATTACK_MONTAGE"));
		AttackMontage = ATTACK_MONTAGE.Object;
	}
}

void UEnemyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();

	if (!::IsValid(Pawn)) return;

	if (!IsDead)
	{
		CurrentPawnSpeed = Pawn->GetVelocity().Size();
	}
}

void UEnemyAnimInstance::PlayAttackMontage()
{
	if (!Montage_IsPlaying(AttackMontage))
	{
		UE_LOG(LogTemp, Display, TEXT("Montage_Play"));

		Montage_Play(AttackMontage, 1.0f);
	}
}

void UEnemyAnimInstance::JumpToAttackMontageSection(int32 NewSection)
{
	Montage_JumpToSection(GetAttackMontageSectionName(NewSection), AttackMontage);
}

void UEnemyAnimInstance::AnimNotify_AttackHitCheck()
{
	OnAttackHitCheck.Broadcast();
}

void UEnemyAnimInstance::AnimNotify_NextAttackCheck()
{
	OnNextAttackCheck.Broadcast();
}

FName UEnemyAnimInstance::GetAttackMontageSectionName(int32 Section)
{
	return FName(*FString::Printf(TEXT("Attack%d"), Section));
}
