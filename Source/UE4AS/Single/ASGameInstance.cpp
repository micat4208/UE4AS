#include "ASGameInstance.h"

void UASGameInstance::Init()
{
	Super::Init();

	bIsPlaying = false;
	CurrentScore = 0.0f;
}
