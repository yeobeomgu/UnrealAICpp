// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 *
 */
class TEAMPROJECT_API ReadMe_about_Rule
{
public:
	/*******
	* 
	* https://docs.unrealengine.com/4.27/ko/ProductionPipelines/DevelopmentSetup/CodingStandard/
	* �𸮾� ���� ���� �� �� ���� ���ø� �˴ϴ�.
	* �� �� ��Ģ
	*
	�ڵ� �ۼ� ��Ģ

	1. ���̹� ��Ģ - �󸮾� API ��� �� �����ϰ�
		1) Ŭ���� ��� ���� �� �Լ�
			�빮�� ����
			���� ���� ��/�ҹ��ڷ� ����
			���Ӹ� ��� X
			ex) PlayerController
		
		2) ���� ����
			�ҹ��� ����
			���� ���� ��/�ҹ��ڷ� ����
			���Ӹ� ���
			ex) pContr -> player controller �� �ǹ���

		3) �Լ��� �Ű�����
			��� �ҹ���
			���Ӹ� ���
			ex) void Test(APlayerController pc); pc -> player controller �� �ǹ���

		4) enum / #define ��� �� ��� �빮��
			ex) enum class ITEMTYPE {} / #define BASICHP 10;

	2. ���� ���� �� ���ǻ���
		1) ��� ������ Private / Protected �� �����Ѵ�. public ���� ���� ����
		��¥�� ��� ������ �����Ϳ��� ��밡��
			private -> �� �̻� ����� ���� ���� ����
			protected -> ��� ���� Ŭ���������� ����� ����

		2) �׷��� ��� ������ Getter �� Setter �Լ��� ������.
		2-1) Getter �� Setter �Լ��� ��쿡�� �� �ٷ� �ۼ��ϸ� �ȴ�.
		���� cpp �� ������ �ʿ� ����.
			ex)
			private:
				int CurrentHP
				class AnimMontage* ReloadAnimMontage;
			
			public:
			// Getter
			int GetCurrentHP() { return CurrentHP; }
			AnimMontage* GetReloadAnimMontage() { return ReloadAnimMontage; }

			// Setter
			void SetCurrentHP(int curhp) { CurrentHP = curhp; }
			void SetReloadAnimMontage(AnimMontage* reloadanim) { ReloadAnimMontage = reloadanim; }


		3) ��� �𸮾� ������ ���� ���� �� �����ͷ� �����Ѵ�.
			�𸮾� ���� ���� �� class Ű���� �ʼ�
			ex) StaticMeshComponent ���� ���� ��
				class StaticMeshComponent* StaticMesh;

		4) bool, enum �� Ư�� ������ ��� �̸��� �˷��ش�.
			ex) bool bIsCanUse;
			ITEMTYPE eItemType;

		5) Ư�� ��Ȳ �����ϰ� ��� ������ �����ڿ��� �ʱ�ȭ�Ѵ�.
		���� ������ ������ ��쿡�� ������ �� ���������� nullptr �� �ʱ�ȭ�ϱ⵵ ��


		�� �ʿ��ϴٰ� �����ϴ� ��Ģ ������ �߰����ֽø� �˴ϴ�!!!!!!
			
	

	******/
};
