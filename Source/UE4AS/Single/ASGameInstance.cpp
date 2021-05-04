#include "ASGameInstance.h"
#include "Struct/SaveData/SaveData.h"

void UASGameInstance::Init()
{
	Super::Init();

	bIsPlaying = false;
	CurrentScore = 0.0f;

	TryUpdateBestScore();
}

void UASGameInstance::TryUpdateBestScore()
{
	FSaveData saveData;
	bool loadCompleted = LoadJson(TEXT("SaveData"), saveData);
	if (!loadCompleted) saveData = FSaveData(0.0f, FDateTime::Now());
	else
	{
		if (CurrentScore > saveData.BestScore)
		{ 
			if (FMath::IsNearlyZero(CurrentScore)) return;

			saveData = FSaveData(CurrentScore, FDateTime::Now());
		}
	}

	SaveJson(TEXT("SaveData"), saveData);
}
