#pragma once

#include "UE4AS.h"
#include "Actor/PlayerController/GamePlayerControllerBase.h"
#include "GamePlayerController.generated.h"

UCLASS()
class UE4AS_API AGamePlayerController : 
	public AGamePlayerControllerBase
{
	GENERATED_BODY()
	
private :
	TSubclassOf<class UGameWidget> BP_GameWidget;

public :
	AGamePlayerController(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void OnPossess(APawn* aPawn) override;





};
