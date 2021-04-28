#pragma once

#include "UE4AS.h"
#include "GameFramework/Character.h"
#include "GamePlayerCharacter.generated.h"

UCLASS()
class UE4AS_API AGamePlayerCharacter : public ACharacter
{
	GENERATED_BODY()

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
