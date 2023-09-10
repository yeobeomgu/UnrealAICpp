// Fill out your copyright notice in the Description page of Project Settings.


#include "BG/EnemyCharacter.h"
#include "EnemyAnimInstance.h"
#include "Components/CapsuleComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyAIController.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	IsAttacking = false;
	
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Enemy"));

	MaxCombo = 6;
	AttackEndComboState();

	AttackRange = 200.0f;
	AttackRadius = 50.0f;

	AIControllerClass = AEnemyAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

}

void AEnemyCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	AttackAnim = Cast<UEnemyAnimInstance>(GetMesh()->GetAnimInstance());

	
	AttackAnim->OnMontageEnded.AddDynamic(this, &AEnemyCharacter::OnAttackMontageEnded);

	AttackAnim->OnNextAttackCheck.AddLambda([this]()->void {
		CanNextCombo = false;

		if (IsComboInputOn)
		{
			AttackStartComboState();
			AttackAnim->JumpToAttackMontageSection(CurrentCombo);
		}
	});
}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Move Forward / Backward"), this, &AEnemyCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Look Up / Down Mouse"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("Move Right / Left"), this, &AEnemyCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn Right / Left Mouse"), this, &AEnemyCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &AEnemyCharacter::Attack);


	


}

float AEnemyCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float FinalDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	UE_LOG(LogTemp, Warning, TEXT("Actor : %s Damage : %f"), *GetName(), FinalDamage);

	if (FinalDamage > 0.0f)
	{
		AttackAnim->SetDeadAnim();
		SetActorEnableCollision(false);
	}

	return FinalDamage;
}

void AEnemyCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void AEnemyCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void AEnemyCharacter::Attack()
{
	if (IsAttacking)
	{
		if (CanNextCombo)
		{
			IsComboInputOn = true;
		}
	}

	else
	{
		AttackStartComboState();
		AttackAnim->PlayAttackMontage();
		AttackAnim->JumpToAttackMontageSection(CurrentCombo);
		IsAttacking = true;
	}

	
	AttackAnim->PlayAttackMontage();

	IsAttacking = true;
	UE_LOG(LogTemp, Display, TEXT("Attack!!!"));
}

void AEnemyCharacter::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	IsAttacking = false;
	AttackEndComboState();

	AttackAnim->OnAttackHitCheck.AddUObject(this, &AEnemyCharacter::AttackCheck);
	
}

void AEnemyCharacter::AttackStartComboState()
{
	CanNextCombo = true;
	IsComboInputOn = false;
	CurrentCombo = FMath::Clamp<int32>(CurrentCombo + 1, 1, MaxCombo);
}

void AEnemyCharacter::AttackEndComboState()
{
	IsComboInputOn = false;
	CanNextCombo = false;
	CurrentCombo = 0;
}

void AEnemyCharacter::AttackCheck()
{
	FHitResult HitResult;
	FCollisionQueryParams Params(NAME_None, false, this);
	bool bResult = GetWorld()->SweepSingleByChannel(
		HitResult,
		GetActorLocation(),
		GetActorLocation() + GetActorForwardVector() * AttackRange,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel12,
		FCollisionShape::MakeSphere(AttackRadius),
		Params);
	
#if ENABLE_DRAW_DEBUG
	FVector TraceVec = GetActorForwardVector() * AttackRange;
	FVector Center = GetActorLocation() + TraceVec * 0.5f;
	float HalfHeight = AttackRange * 0.5f + AttackRadius;
	FQuat CapsuleRot = FRotationMatrix::MakeFromZ(TraceVec).ToQuat();
	FColor DrawColor = bResult ? FColor::Green : FColor::Red;
	float DebugLifeTime = 5.0f;

	DrawDebugCapsule(GetWorld(),
		Center,
		HalfHeight,
		AttackRadius,
		CapsuleRot,
		DrawColor,
		false,
		DebugLifeTime);

#endif
	if (bResult)
	{
		if (HitResult.GetActor()->IsValidLowLevel())
		{
			UGameplayStatics::ApplyDamage(HitResult.GetActor(), 50.0f, GetController(), this, UDamageType::StaticClass());
		
			
		}
	}
}



