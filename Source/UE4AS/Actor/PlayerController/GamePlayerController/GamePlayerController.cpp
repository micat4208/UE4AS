#include "GamePlayerController.h"

#include "Widget/GameWidget/GameWidget.h"

AGamePlayerController::AGamePlayerController(const FObjectInitializer& ObjectInitializer) : 
	Super(ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<UGameWidget> BP_GAME_WIDGET(
		TEXT("WidgetBlueprint'/Game/Blueprints/Widget/BP_Game.BP_Game_C'"));
	if (BP_GAME_WIDGET.Succeeded()) BP_GameWidget = BP_GAME_WIDGET.Class;
}

void AGamePlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	// ���� ���� ���
	/// - CreateWidget<WidgetType>(���� ��ü�� ������ ��ü, ��� ���� UClass);
	/// - ������ ���� ��ü->AddToViewport()
	CreateWidget<UGameWidget>(this, BP_GameWidget)->AddToViewport();
}
