#include "GameWidget.h"
#include "Actor/Character/GamePlayerCharacter/GamePlayerCharacter.h"

#include "Components/Image.h"
#include "Components/CanvasPanelSlot.h"


void UGameWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//Image_Current = Cast<UImage>(GetWidgetFromName(TEXT("Image_Current")));
}

void UGameWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	MoveCurrentImage();
}

void UGameWidget::InitializeGameWidget(AGamePlayerCharacter* playerCharacter)
{
	PlayerCharacter = playerCharacter;
}

void UGameWidget::MoveCurrentImage()
{
	// Image_Bar �� CanvasPanelSlot �� ����ϴ�.
	UCanvasPanelSlot* barSlot = Cast<UCanvasPanelSlot>(Image_Bar->Slot);
	// Image_Current �� CanvasPanelSlot �� ����ϴ�.
	UCanvasPanelSlot* currentImageSlot = Cast<UCanvasPanelSlot>(Image_Current->Slot);

	// Image_Current �� ��ġ�� �����մϴ�.
	currentImageSlot->SetPosition(
		FVector2D(PlayerCharacter->GetHp() * (barSlot->GetSize().X * 0.01f), 0.0f));
}