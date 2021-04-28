#pragma once

#include "UE4AS.h"
#include "GameFramework/Character.h"
#include "GamePlayerCharacter.generated.h"

UCLASS()
class UE4AS_API AGamePlayerCharacter : public ACharacter
{
	GENERATED_BODY()

private :
	// UPlayerCharacterAnimInstance 와 상속 관계에 있는 클래스를 나타냅니다.
	TSubclassOf<class UPlayerCharacterAnimInstance> BP_PlayerCharacterAnimInstance;

private :
	// 조종하는 플레이어 컨트롤러를 나타냅니다.
	UPROPERTY()
	class AGamePlayerControllerBase* PlayerController;

	// 목표 체력을 나타냅니다.
	float TargetHp;

	// 캐릭터 체력을 나타냅니다.
	float Hp;

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
	void InputJump();

public :
	// 현재 체력 값을 반환합니다.
	FORCEINLINE float GetHp() const
	{ return Hp; }

	// Hp 에 값을 더합니다.
	void AddHp(float add);

private :
	// 대미지를 입었을 경우 호출될 메서드
	UFUNCTION()
	void OnHit(
		AActor*						DamagedActor,
		float						Damage,
		const class UDamageType*	DamageType,
		class AController*			InstigatedBy,
		AActor*						DamageCauser);
	/// - DamagedActor	: 대미지를 입은 액터를 나타냅니다.
	/// - Damage		: 입은 피해를 나타냅니다.
	/// - DamageType	: 대미지 타입이 전달됩니다.
	/// - InstigatedBy	: 피해를 준 컨트롤러가 전달됩니다.
	/// - DamageCauser	: 피해를 준 액터가 전달됩니다.

};
