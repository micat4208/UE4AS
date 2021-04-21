#pragma once

#include "UE4AS.h"
#include "GameFramework/Character.h"
#include "GamePlayerCharacter.generated.h"

UCLASS()
class UE4AS_API AGamePlayerCharacter : public ACharacter
{
	GENERATED_BODY()

private :
	// 조종하는 플레이어 컨트롤러를 나타냅니다.
	UPROPERTY()
	class AGamePlayerControllerBase* PlayerController;

public:
	AGamePlayerCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void PossessedBy(AController* NewController) override;
	virtual void Tick(float DeltaTime) override;

	// [프로젝트 세팅 -> 입력] 에 매핑한 키 입력 이벤트를 폰에 등록합니다.
	/// - PlayerInputComponent : 액터에 입력 이벤트를 등록하는 기능을 제공하는 컴포넌트입니다.
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private :
	void InputHorizontal(float axis);
};
