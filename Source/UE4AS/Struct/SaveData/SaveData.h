#pragma once

#include "CoreMinimal.h"
#include "SaveData.generated.h"

USTRUCT()
struct UE4AS_API FSaveData
{
	GENERATED_USTRUCT_BODY()

public :
	UPROPERTY()
	float BestScore;

	UPROPERTY()
	int32 Year;
	UPROPERTY()
	int32 Month;
	UPROPERTY()
	int32 Day;

	UPROPERTY()
	int32 Hours;
	UPROPERTY()
	int32 Minutes;
	UPROPERTY()
	int32 Seconds;


public:
	FSaveData();
	FSaveData(float bestScore, FDateTime dateTime);

};
