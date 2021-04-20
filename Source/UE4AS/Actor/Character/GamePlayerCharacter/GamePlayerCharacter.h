#pragma once

#include "UE4AS.h"
#include "GameFramework/Character.h"
#include "GamePlayerCharacter.generated.h"

UCLASS()
class UE4AS_API AGamePlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AGamePlayerCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	// [������Ʈ ���� -> �Է�] �� ������ Ű �Է� �̺�Ʈ�� ���� ����մϴ�.
	/// - PlayerInputComponent : ���Ϳ� �Է� �̺�Ʈ�� ����ϴ� ����� �����ϴ� ������Ʈ�Դϴ�.
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private :
	void InputHorizontal(float axis);
};
