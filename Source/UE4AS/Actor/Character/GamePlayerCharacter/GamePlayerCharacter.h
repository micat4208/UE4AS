#pragma once

#include "UE4AS.h"
#include "GameFramework/Character.h"
#include "GamePlayerCharacter.generated.h"


// 이벤트
/// - 선언된 클래스 내에서만 호출할 수 있는 Multicast Delegate 입니다.

// 선언
/// - DECLARE_EVENT(OwningType, EventName) : 이벤트를 생성합니다.
/// - DECLARE_EVENT_OneParam(OwningType, EventName, Param1Type) : 매개 변수가 하나인 이벤트를 생성합니다.
/// - DECLARE_EVENT_TwoParams(OwningType, EventName, Param1Type, Param2Type) : 매개 변수가 둘인 이벤트를 생성합니다.

// 대리자와 다른 점
/// - 대리자는 선언된 클래스 외부에서도 호출될 수 있지만, 이벤트는 외부에서 호출될 수 없음.
/// - 대리자는 반환 타입을 설정할 수 있지만, 이벤트는 무조건 void 만 가능.
/// - Multicast Delegate 는 Broadcast() 를 통해 바인딩된 메서드 / 함수를 호출할 수 있으며,
///   만약 바인딩되지 않은 상태에서 Broadcast() 가 호출된다면 위험함.
///   -> IsBound() 를 통해 바인딩된 메서드 존재 여부를 확인하는 작업이 꼭 필요함.
///   이벤트는 바인딩이 되지 않은 상태에서 Broadcast() 가 이루어져도 안전합니다.

DECLARE_EVENT(AGamePlayerCharacter, FCharacterDieEvent)
DECLARE_EVENT(AGamePlayerCharacter, FOnOverlapEvent)

UCLASS()
class UE4AS_API AGamePlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public :
	// 캐릭터 사망 시 발생하는 이벤트
	FCharacterDieEvent CharacterDieEvent;

	// FallinObject 와 겹쳤을 경우 발생하는 이벤트
	FOnOverlapEvent OnOverlapEvent;

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

	// 캐릭터 사망 상태를 나타냅니다.
	bool bIsDie;

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
