#include "TitlePlayerController.h"
#include "Widget/TitleWidget/TitleWidget.h"

ATitlePlayerController::ATitlePlayerController(const FObjectInitializer& ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<UTitleWidget> BP_TITLE_WIDGET(
		TEXT("WidgetBlueprint'/Game/Blueprints/Widget/BP_Title.BP_Title_C'"));
	if (BP_TITLE_WIDGET.Succeeded()) BP_TitleWidget = BP_TITLE_WIDGET.Class;
}

void ATitlePlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	auto titleWidget = CreateWidget<UTitleWidget>(this, BP_TitleWidget);
	titleWidget->AddToViewport();

	// Ŀ���� ǥ���մϴ�.
	bShowMouseCursor = true;

	// �Է� ��带 �����մϴ�.
	SetInputMode(FInputModeUIOnly());
}
