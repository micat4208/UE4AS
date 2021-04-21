#include "PlayerCharacterAnimInstance.h"
#include "Actor/Character/GamePlayerCharacter/GamePlayerCharacter.h"

void UPlayerCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);


	// �� AnimInstance Ŭ������ ����ϴ� Pawn ��ü�� ����ϴ�.
	AGamePlayerCharacter* owner = Cast<AGamePlayerCharacter>(TryGetPawnOwner());
	
	// ���� ������ �ϴ� Pawn ��ü�� ��ȿ���� �ʴٸ� �ϴ� ������ �������� �ʽ��ϴ�.
	if (!IsValid(owner)) return;

	// ĳ������ �ӷ��� ����ϴ�.
	Speed = owner->GetVelocity().Size();
	/// - GetVelocity() : pawn �� ����� �ӵ��� ����ϴ�.
	/// - vector.Size() : vector �� ���̸� ��ȯ�մϴ�.


}