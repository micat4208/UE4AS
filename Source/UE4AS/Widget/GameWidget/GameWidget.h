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
	// ü�� ���¸� ��Ÿ���� �̹����� �¿�� �̵���ŵ�ϴ�.
	void MoveCurrentImage();
};
