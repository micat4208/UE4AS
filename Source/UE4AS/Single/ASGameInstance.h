#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ASGameInstance.generated.h"

// ���� ��ü�� �����մϴ�.
UCLASS()
class UE4AS_API UASGameInstance final : 
	public UGameInstance
{
	GENERATED_BODY()

private :
	// ���� �÷��� ���¸� ��Ÿ���ϴ�.
	bool bIsPlaying;

	// ���� ������ ��Ÿ���ϴ�.
	float CurrentScore;

public :
	// GameInstance �� ������ ���� �� �ѹ� ȣ��Ǵ� �޼����Դϴ�.
	virtual void Init() override;

public :
	// ���� ������ ��ȯ�մϴ�.
	FORCEINLINE float GetCurrentScore() const
	{ return CurrentScore; }

	// ������ ���½�ŵ�ϴ�.
	FORCEINLINE void ResetCurrentScore()
	{ CurrentScore = 0.0f; }

	// ������ ���մϴ�.
	FORCEINLINE void AddCurrentScore(float addScore)
	{ if (bIsPlaying) CurrentScore += addScore; }
	
	// ���� �÷��� ���¸� ��Ÿ���ϴ�.
	FORCEINLINE bool IsPlaying() const
	{ return bIsPlaying; }

	// ���� ����
	FORCEINLINE void StartGame()
	{ bIsPlaying = true; }

	// ���� ��
	FORCEINLINE void EndGame()
	{ bIsPlaying = false; }

};
