#pragma once

#include "UE4AS.h"
#include "Components/ActorComponent.h"

#include "FloatingMovementComponent.generated.h"
/// - UHT �� ���� �ڵ����� �����Ǵ� �ΰ� ������ �ǹ��մϴ�.
/// - ����� #include �� ���� �ϴܿ� �ۼ��մϴ�.


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE4AS_API UFloatingMovementComponent : public UActorComponent
{
	GENERATED_BODY()
/// - �׻� Ŭ���� ù �ٿ� �ۼ��Ǿ�� �ϸ�,
//    Ŭ������ ������ �ʿ��� ������ �����ϵ��� �����մϴ�.

private :
	// ������ �ʱ� ��ġ�� ��Ÿ���ϴ�.
	FVector ActorBeginLocation;

	// �ʵ忡 UPROPERTY() �� ���Ǹ� ���÷��� �ý��ۿ� �ʵ尡 ��ϵ˴ϴ�.
	// - �⺻ ���� ������� �� ������, Ư���� �����ڸ� �߰��Ͽ� �����Ϳ��� ��ȣ�ۿ� �����ϵ��� ������ �� �ֽ��ϴ�.
	/// - EditAnywhere : �������� ������ â���� ������ �������� �ǹ��մϴ�.
	/// - VisibleAnywhere : �������� ������ â���� �б� �������� ������ �ǹ��մϴ�.
	UPROPERTY(EditAnywhere)
	float FloatingValue;

	UPROPERTY(EditAnywhere)
	float FloatingSpeed;

public:	
	UFloatingMovementComponent();

protected:
	// ������ ���۵� ���� ������ �����Ǿ��� ��� �� �� ȣ��Ǵ� �޼����Դϴ�.
	virtual void BeginPlay() override;

public:	
	/// �� �����Ӹ��� ȣ��Ǵ� �޼���
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
private :
	// �յ� �ߴ� �������� �����մϴ�.
	void FloatingMovement(float dt);
	
};
