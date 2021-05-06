#pragma once

#include "CoreMinimal.h"
#include "Actor/PlayerController/GamePlayerControllerBase.h"
#include "TitlePlayerController.generated.h"


UCLASS()
class UE4AS_API ATitlePlayerController : public AGamePlayerControllerBase
{
	GENERATED_BODY()

private :
	TSubclassOf<class UTitleWidget> BP_TitleWidget;
	class USoundCue* SC_TitleBackground;


public:
	ATitlePlayerController(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void OnPossess(APawn* aPawn) override;

	
};
