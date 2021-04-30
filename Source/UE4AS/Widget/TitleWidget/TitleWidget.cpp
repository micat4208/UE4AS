#include "TitleWidget.h"

#include "Components/Button.h"

void UTitleWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Button_GameStart->OnClicked.AddDynamic(this, &UTitleWidget::OnGameStartButtonClicked);
	Button_Quit->OnClicked.AddDynamic(this, &UTitleWidget::OnQuitButtonClicked);


}

void UTitleWidget::OnGameStartButtonClicked()
{
	LOG(TEXT("OnGameStartButtonClicked"));
}

void UTitleWidget::OnQuitButtonClicked()
{
	LOG(TEXT("OnQuitButtonClicked"));
}
