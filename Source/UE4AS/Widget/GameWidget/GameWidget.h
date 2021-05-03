#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameWidget.generated.h"

UCLASS()
class UE4AS_API UGameWidget : 
	public UUserWidget
{
	GENERATED_BODY()

private :
	UPROPERTY(meta = (BindWidget))
	class UImage* Image_Bar;

	UPROPERTY(meta = (BindWidget))
	class UImage* Image_Current;

	UPROPERTY(meta = (BindWidget))
	class UOverlay* Overlay_GameOver;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Text_GoToTitle;
	/// - BindWidget : 필드와 같은 형식과 이름으로 추가된 위젯을 찾아 필드에 바인딩시킵니다.

	UPROPERTY(meta = (BindWidget))
	class UTextBlock * Text_Score;

private :
	int32 TimerCount;
	FTimerHandle TimerHandle;


private :
	class AGamePlayerCharacter* PlayerCharacter;

protected :
	virtual void NativeConstruct() override;

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

public :
	// 이 위젯을 초기화 시킵니다.
	void InitializeGameWidget(class AGamePlayerCharacter* playerCharacter);

private :
	// 체력 상태를 나타내는 이미지를 좌우로 이동시킵니다.
	void MoveCurrentImage();
};
