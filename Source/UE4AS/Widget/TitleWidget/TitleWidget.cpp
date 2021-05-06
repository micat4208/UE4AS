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

	// ���� �ִϸ��̼��� ����մϴ�.
	PlayAnimation(Floating_Logo, 0.0f, 0);

	// ���� �ؽ�Ʈ ����
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
	// ���� ������ ��ȯ�մϴ�.
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("GameMap"));
}

void UTitleWidget::OnQuitButtonClicked()
{
	// ������ �����ŵ�ϴ�.
	UKismetSystemLibrary::QuitGame(
		GetWorld(),
		UGameplayStatics::GetPlayerController(GetWorld(), 0),
		EQuitPreference::Quit, false);
}
