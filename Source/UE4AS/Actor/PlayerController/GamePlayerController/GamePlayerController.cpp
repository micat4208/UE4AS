#include "GamePlayerController.h"

#include "Sound/SoundCue.h"
#include "Actor/Character/GamePlayerCharacter/GamePlayerCharacter.h"

#include "Widget/GameWidget/GameWidget.h"

AGamePlayerController::AGamePlayerController(const FObjectInitializer& ObjectInitializer) : 
	Super(ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<UGameWidget> BP_GAME_WIDGET(
		TEXT("WidgetBlueprint'/Game/Blueprints/Widget/BP_Game.BP_Game_C'"));
	if (BP_GAME_WIDGET.Succeeded()) BP_GameWidget = BP_GAME_WIDGET.Class;

	static ConstructorHelpers::FObjectFinder<USoundCue> SC_GAME_BACKGROUND(
		TEXT("SoundCue'/Game/Resources/Sound/SC_GameBackground.SC_GameBackground'"));
	if (SC_GAME_BACKGROUND.Succeeded()) SC_GameBackground = SC_GAME_BACKGROUND.Object;
}

void AGamePlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	// ���� ���� ���
	/// - CreateWidget<WidgetType>(���� ��ü�� ������ ��ü, ��� ���� UClass);
	/// - ������ ���� ��ü->AddToViewport()
	UGameWidget* gameWidget = CreateWidget<UGameWidget>(this, BP_GameWidget);
	gameWidget->AddToViewport();
	gameWidget->InitializeGameWidget(Cast<AGamePlayerCharacter>(aPawn));

	// Ŀ���� ����ϴ�.
	bShowMouseCursor = false;

	// �Է� ��带 GameOnly �� �����մϴ�.
	SetInputMode(FInputModeGameOnly());

	// ���� ���
	UGameplayStatics::PlaySound2D(this, SC_GameBackground);
}
