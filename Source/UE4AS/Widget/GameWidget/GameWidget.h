#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameWidget.generated.h"

UCLASS()
class UE4AS_API UGameWidget : public UUserWidget
{
	GENERATED_BODY()


protected :
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private :
	// 체력 상태를 나타내는 이미지를 좌우로 이동시킵니다.
	void MoveCurrentImage();
};
