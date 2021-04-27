#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameWidget.generated.h"

UCLASS()
class UE4AS_API UGameWidget : 
	public UUserWidget
{
	GENERATED_BODY()

private :
	UPROPERTY(meta = (BindWidget))
	class UImage* Image_Bar;
	UPROPERTY(meta = (BindWidget))
	class UImage* Image_Current;
	/// - BindWidget : �ʵ�� ���� ���İ� �̸����� �߰��� ������ ã�� �ʵ忡 ���ε���ŵ�ϴ�.

private :
	class AGamePlayerCharacter* PlayerCharacter;

protected :
	virtual void NativeConstruct() override;

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

public :
	// �� ������ �ʱ�ȭ ��ŵ�ϴ�.
	void InitializeGameWidget(class AGamePlayerCharacter* playerCharacter);

private :
	// ü�� ���¸� ��Ÿ���� �̹����� �¿�� �̵���ŵ�ϴ�.
	void MoveCurrentImage();
};
