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
	// 카메라 뷰를 설정합니다.
	void SetCameraView();
	
};
