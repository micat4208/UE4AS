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
	// 이 AnimInstance 를 사용하는 Pawn 의 속력을 나타냅니다.
	/// 블루프린트에서 읽기 전용으로 이 필드를 노출시킵니다.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Speed;


public :
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
};
