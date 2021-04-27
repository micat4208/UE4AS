#include "GamePlayerController.h"

#include "Actor/Character/GamePlayerCharacter/GamePlayerCharacter.h"

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

	// 困连 剁快绰 规过
	/// - CreateWidget<WidgetType>(困连 按眉甫 家蜡且 按眉, 剁匡 困连 UClass);
	/// - 积己等 困连 按眉->AddToViewport()
	UGameWidget* gameWidget = CreateWidget<UGameWidget>(this, BP_GameWidget);
	gameWidget->AddToViewport();
	gameWidget->InitializeGameWidget(Cast<AGamePlayerCharacter>(aPawn));
}
