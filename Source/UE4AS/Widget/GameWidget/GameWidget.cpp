#include "GameWidget.h"

#include "Single/ASGameInstance.h"

#include "Actor/Character/GamePlayerCharacter/GamePlayerCharacter.h"

#include "Components/Image.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Overlay.h"
#include "Components/TextBlock.h"


void UGameWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//Image_Current = Cast<UImage>(GetWidgetFromName(TEXT("Image_Current")));

	// GameOver 패널을 숨긴 상태로 시작합니다.
	Overlay_GameOver->SetVisibility(ESlateVisibility::Collapsed);

	TimerCount = 2;
}

void UGameWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	MoveCurrentImage();
}

void UGameWidget::InitializeGameWidget(AGamePlayerCharacter* playerCharacter)
{
	PlayerCharacter = playerCharacter;

	PlayerCharacter->CharacterDieEvent.AddLambda(
		[this]()
		{
			Overlay_GameOver->SetVisibility(ESlateVisibility::SelfHitTestInvisible);

			// 타이머를 실행시킵니다.
			
			FTimerDelegate timerDelegate;
			timerDelegate.BindLambda([this]()
				{
					// 3초가 지났다면
					if (TimerCount < 0)
					{
						// 타이머 종료
						GetWorld()->GetTimerManager().ClearTimer(TimerHandle);

						// TitleMap 으로 전환시킵니다.
						UGameplayStatics::OpenLevel(GetWorld(), TEXT("TitleMap"));

						return;
					}


					Text_GoToTitle->SetText(
						FText::FromString(
							FString::Printf(TEXT("%d초 후 타이틀로 이동합니다."), TimerCount)
						)
					);

					--TimerCount;

				});

			GetWorld()->GetTimerManager().SetTimer(TimerHandle, timerDelegate, 1.0f, true);


		});

	// 점수 갱신
	PlayerCharacter->OnOverlapEvent.AddLambda([this]()
		{
			// 현재 점수를 얻습니다.
			float currentScore = GetGameInstance<UASGameInstance>()->GetCurrentScore();

			// 표시시킬 문자열을 나타냅니다.
			FString text = FString::Printf(
				TEXT("현재 점수\n%.2f"), currentScore);

			Text_Score->SetText(FText::FromString(text));
		});
}

void UGameWidget::MoveCurrentImage()
{
	// Image_Bar 의 CanvasPanelSlot 을 얻습니다.
	UCanvasPanelSlot* barSlot = Cast<UCanvasPanelSlot>(Image_Bar->Slot);
	// Image_Current 의 CanvasPanelSlot 을 얻습니다.
	UCanvasPanelSlot* currentImageSlot = Cast<UCanvasPanelSlot>(Image_Current->Slot);

	// Image_Current 의 위치를 설정합니다.
	currentImageSlot->SetPosition(
		FVector2D(PlayerCharacter->GetHp() * (barSlot->GetSize().X * 0.01f), 0.0f));
}