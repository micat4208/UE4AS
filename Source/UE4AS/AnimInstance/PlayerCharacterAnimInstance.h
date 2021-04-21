#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerCharacterAnimInstance.generated.h"

UCLASS()
class UE4AS_API UPlayerCharacterAnimInstance final : 
	public UAnimInstance
{
	GENERATED_BODY()

protected :
	// �� AnimInstance �� ����ϴ� Pawn �� �ӷ��� ��Ÿ���ϴ�.
	/// �������Ʈ���� �б� �������� �� �ʵ带 �����ŵ�ϴ�.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Speed;


public :
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
};
