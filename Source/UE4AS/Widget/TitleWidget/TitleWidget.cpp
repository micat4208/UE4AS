#include "TitleWidget.h"

#include "Components/Button.h"

void UTitleWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Button_GameStart->OnClicked.AddDynamic(this, &UTitleWidget::OnGameStartButtonClicked);
	Button_Quit->OnClicked.AddDynamic(this, &UTitleWidget::OnQuitButtonClicked);

	// ���� �ִϸ��̼��� ����մϴ�.
	PlayAnimation(Floating_Logo, 0.0f, 0);
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
