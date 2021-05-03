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

protected :
	virtual void NativeConstruct() override;


private :
	UFUNCTION()
	void OnGameStartButtonClicked();

	UFUNCTION()
	void OnQuitButtonClicked();

	
};
