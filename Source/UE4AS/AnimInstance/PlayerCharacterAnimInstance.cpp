#include "PlayerCharacterAnimInstance.h"
#include "Actor/Character/GamePlayerCharacter/GamePlayerCharacter.h"

void UPlayerCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);


	// 이 AnimInstance 클래스를 사용하는 Pawn 객체를 얻습니다.
	AGamePlayerCharacter* owner = Cast<AGamePlayerCharacter>(TryGetPawnOwner());
	
	// 만약 얻으려 하는 Pawn 객체가 유효하지 않다면 하단 구문을 실행하지 않습니다.
	if (!IsValid(owner)) return;

	// 캐릭터의 속력을 얻습니다.
	Speed = owner->GetVelocity().Size();
	/// - GetVelocity() : pawn 에 적용된 속도를 얻습니다.
	/// - vector.Size() : vector 의 길이를 반환합니다.


}