#pragma once

#include "UE4AS.h"
#include "GameFramework/PlayerController.h"
#include "GamePlayerControllerBase.generated.h"

UCLASS()
class UE4AS_API AGamePlayerControllerBase : 
	public APlayerController
{
	GENERATED_BODY()

protected :
	virtual void BeginPlay() override;


private :
	// ī�޶� �並 �����մϴ�.
	void SetCameraView();
	
};
