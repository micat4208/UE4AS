#include "TitleWidget.h"

#include "Single/ASGameInstance.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"

#include "Struct/SaveData/SaveData.h"

void UTitleWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Button_GameStart->OnClicked.AddDynamic(this, &UTitleWidget::OnGameStartButtonClicked);
	Button_Quit->OnClicked.AddDynamic(this, &UTitleWidget::OnQuitButtonClicked);

	// 위젯 애니메이션을 재생합니다.
	PlayAnimation(Floating_Logo, 0.0f, 0);

	// 점수 텍스트 갱신
	UpdateScoreText();
}

void UTitleWidget::UpdateScoreText()
{
	UASGameInstance* gameInstance = GetGameInstance<UASGameInstance>();

	FSaveData saveData;
	bool loadComp = gameInstance->LoadJson<FSaveData>(TEXT("SaveData"), saveData);

	if (loadComp)
	{
		Text_Date->SetText(saveData.GetDateText());
		Text_Score->SetText(saveData.GetScoreText());
	}

}

void UTitleWidget::OnGameStartButtonClicked()
{
	// 게임 맵으로 전환합니다.
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("GameMap"));
}

void UTitleWidget::OnQuitButtonClicked()
{
	// 게임을 종료시킵니다.
	UKismetSystemLibrary::QuitGame(
		GetWorld(),
		UGameplayStatics::GetPlayerController(GetWorld(), 0),
		EQuitPreference::Quit, false);
}
