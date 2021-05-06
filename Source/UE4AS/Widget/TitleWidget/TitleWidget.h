#pragma once

#include "UE4AS.h"
#include "Blueprint/UserWidget.h"
#include "TitleWidget.generated.h"

UCLASS()
class UE4AS_API UTitleWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(meta = (BindWidgetAnim))
	class UWidgetAnimation * Floating_Logo;

	UPROPERTY(meta = (BindWidget))
	class UButton* Button_GameStart;

	UPROPERTY(meta = (BindWidget))
	class UButton* Button_Quit;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Text_Date;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Text_Score;

protected :
	virtual void NativeConstruct() override;

private :
	// ���� Text �� �����մϴ�.
	void UpdateScoreText();


private :
	UFUNCTION()
	void OnGameStartButtonClicked();

	UFUNCTION()
	void OnQuitButtonClicked();

	
};
