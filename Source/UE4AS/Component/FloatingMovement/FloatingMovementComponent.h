#pragma once

#include "UE4AS.h"
#include "Components/ActorComponent.h"

#include "FloatingMovementComponent.generated.h"
/// - UHT 에 의해 자동으로 생성되는 부가 파일을 의미합니다.
/// - 헤더의 #include 문 제일 하단에 작성합니다.


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE4AS_API UFloatingMovementComponent : public UActorComponent
{
	GENERATED_BODY()
/// - 항상 클래스 첫 줄에 작성되어야 하며,
//    클래스가 엔진에 필요한 인프라를 지원하도록 구성합니다.

private :
	// 액터의 초기 위치를 나타냅니다.
	FVector ActorBeginLocation;

	// 필드에 UPROPERTY() 가 사용되면 리플렉션 시스템에 필드가 등록됩니다.
	// - 기본 값을 보장받을 수 있으며, 특정한 지정자를 추가하여 에디터에서 상호작용 가능하도록 설정할 수 있습니다.
	/// - EditAnywhere : 에디터의 디테일 창에서 편집이 가능함을 의미합니다.
	/// - VisibleAnywhere : 에디터의 디테일 창에서 읽기 전용으로 사용됨을 의미합니다.
	UPROPERTY(EditAnywhere)
	float FloatingValue;

	UPROPERTY(EditAnywhere)
	float FloatingSpeed;

public:	
	UFloatingMovementComponent();

protected:
	// 게임이 시작될 때나 게임중 스폰되었을 경우 한 번 호출되는 메서드입니다.
	virtual void BeginPlay() override;

public:	
	/// 매 프레임마다 호출되는 메서드
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
private :
	// 둥둥 뜨는 움직임을 구현합니다.
	void FloatingMovement(float dt);
	
};
