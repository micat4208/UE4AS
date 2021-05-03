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

	// À§Á¬ ¶ç¿ì´Â ¹æ¹ý
	/// - CreateWidget<WidgetType>(À§Á¬ °´Ã¼¸¦ ¼ÒÀ¯ÇÒ °´Ã¼, ¶ç¿ï À§Á¬ UClass);
	/// - »ý¼ºµÈ À§Á¬ °´Ã¼->AddToViewport()
	UGameWidget* gameWidget = CreateWidget<UGameWidget>(this, BP_GameWidget);
	gameWidget->AddToViewport();
	gameWidget->InitializeGameWidget(Cast<AGamePlayerCharacter>(aPawn));

	// Ä¿¼­¸¦ ¼û±é´Ï´Ù.
	bShowMouseCursor = false;

	// ÀÔ·Â ¸ðµå¸¦ GameOnly ·Î ¼³Á¤ÇÕ´Ï´Ù.
	SetInputMode(FInputModeGameOnly());
}
