#pragma once

#include "UE4AS.h"
#include "GameFramework/Character.h"
#include "GamePlayerCharacter.generated.h"


// �̺�Ʈ
/// - ����� Ŭ���� �������� ȣ���� �� �ִ� Multicast Delegate �Դϴ�.

// ����
/// - DECLARE_EVENT(OwningType, EventName) : �̺�Ʈ�� �����մϴ�.
/// - DECLARE_EVENT_OneParam(OwningType, EventName, Param1Type) : �Ű� ������ �ϳ��� �̺�Ʈ�� �����մϴ�.
/// - DECLARE_EVENT_TwoParams(OwningType, EventName, Param1Type, Param2Type) : �Ű� ������ ���� �̺�Ʈ�� �����մϴ�.

// �븮�ڿ� �ٸ� ��
/// - �븮�ڴ� ����� Ŭ���� �ܺο����� ȣ��� �� ������, �̺�Ʈ�� �ܺο��� ȣ��� �� ����.
/// - �븮�ڴ� ��ȯ Ÿ���� ������ �� ������, �̺�Ʈ�� ������ void �� ����.
/// - Multicast Delegate �� Broadcast() �� ���� ���ε��� �޼��� / �Լ��� ȣ���� �� ������,
///   ���� ���ε����� ���� ���¿��� Broadcast() �� ȣ��ȴٸ� ������.
///   -> IsBound() �� ���� ���ε��� �޼��� ���� ���θ� Ȯ���ϴ� �۾��� �� �ʿ���.
///   �̺�Ʈ�� ���ε��� ���� ���� ���¿��� Broadcast() �� �̷������ �����մϴ�.

DECLARE_EVENT(AGamePlayerCharacter, FCharacterDieEvent)
DECLARE_EVENT(AGamePlayerCharacter, FOnOverlapEvent)

UCLASS()
class UE4AS_API AGamePlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public :
	// ĳ���� ��� �� �߻��ϴ� �̺�Ʈ
	FCharacterDieEvent CharacterDieEvent;

	// FallinObject �� ������ ��� �߻��ϴ� �̺�Ʈ
	FOnOverlapEvent OnOverlapEvent;

private :
	// UPlayerCharacterAnimInstance �� ��� ���迡 �ִ� Ŭ������ ��Ÿ���ϴ�.
	TSubclassOf<class UPlayerCharacterAnimInstance> BP_PlayerCharacterAnimInstance;

private :
	// �����ϴ� �÷��̾� ��Ʈ�ѷ��� ��Ÿ���ϴ�.
	UPROPERTY()
	class AGamePlayerControllerBase* PlayerController;

	// ��ǥ ü���� ��Ÿ���ϴ�.
	float TargetHp;

	// ĳ���� ü���� ��Ÿ���ϴ�.
	float Hp;

	// ĳ���� ��� ���¸� ��Ÿ���ϴ�.
	bool bIsDie;

public:
	AGamePlayerCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void PossessedBy(AController* NewController) override;
	virtual void Tick(float DeltaTime) override;

	// [������Ʈ ���� -> �Է�] �� ������ Ű �Է� �̺�Ʈ�� ���� ����մϴ�.
	/// - PlayerInputComponent : ���Ϳ� �Է� �̺�Ʈ�� ����ϴ� ����� �����ϴ� ������Ʈ�Դϴ�.
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private :
	void InputHorizontal(float axis);
	void InputJump();

public :
	// ���� ü�� ���� ��ȯ�մϴ�.
	FORCEINLINE float GetHp() const
	{ return Hp; }

	// Hp �� ���� ���մϴ�.
	void AddHp(float add);

private :
	// ������� �Ծ��� ��� ȣ��� �޼���
	UFUNCTION()
	void OnHit(
		AActor*						DamagedActor,
		float						Damage,
		const class UDamageType*	DamageType,
		class AController*			InstigatedBy,
		AActor*						DamageCauser);
	/// - DamagedActor	: ������� ���� ���͸� ��Ÿ���ϴ�.
	/// - Damage		: ���� ���ظ� ��Ÿ���ϴ�.
	/// - DamageType	: ����� Ÿ���� ���޵˴ϴ�.
	/// - InstigatedBy	: ���ظ� �� ��Ʈ�ѷ��� ���޵˴ϴ�.
	/// - DamageCauser	: ���ظ� �� ���Ͱ� ���޵˴ϴ�.

};
