#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ASGameInstance.generated.h"

// 게임 전체를 관리합니다.
UCLASS()
class UE4AS_API UASGameInstance final : 
	public UGameInstance
{
	GENERATED_BODY()

private :
	// 게임 플레이 상태를 나타냅니다.
	bool bIsPlaying;

	// 현재 점수를 나타냅니다.
	float CurrentScore;

public :
	// GameInstance 가 생성된 이후 단 한번 호출되는 메서드입니다.
	virtual void Init() override;

public :
	// 현재 점수를 반환합니다.
	FORCEINLINE float GetCurrentScore() const
	{ return CurrentScore; }

	// 점수를 리셋시킵니다.
	FORCEINLINE void ResetCurrentScore()
	{ CurrentScore = 0.0f; }

	// 점수를 더합니다.
	FORCEINLINE void AddCurrentScore(float addScore)
	{ if (bIsPlaying) CurrentScore += addScore; }
	
	// 게임 플레이 상태를 나타냅니다.
	FORCEINLINE bool IsPlaying() const
	{ return bIsPlaying; }

	// 게임 시작
	FORCEINLINE void StartGame()
	{ bIsPlaying = true; }

	// 게임 끝
	FORCEINLINE void EndGame()
	{ bIsPlaying = false; }

};
