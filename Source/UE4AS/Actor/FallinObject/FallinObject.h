#pragma once

#include "UE4AS.h"
#include "GameFramework/Actor.h"
#include "Struct/FallinObjectInfo/FallinObjectInfo.h"
#include "FallinObject.generated.h"

UCLASS()
class UE4AS_API AFallinObject final : 
	public AActor
{
	GENERATED_BODY()

private :
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* Mesh;
	/// - VisibleAnywhere : 해당 필드의 값을 에디터에서 확인할 수 있도록 합니다.
	/// - EditAnywhere : 해당 필드의 값을 에디터에서 설정할 수 있도록 합니다.
	
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class URotatingMovementComponent* RotatingMovement;
	
	FFallinObjectInfo* FallinObjectInfo;

private:
	// 떨어지는 속력을 나타냅니다.
	float FallDownSpeed;

public:	
	AFallinObject();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public :
	// FallinObject 를 초기화합니다.
	void InitializeFallinObject(FFallinObjectInfo* fallinObjInfo, float falldownSpeed);

private :
	// 떨어지는 이동을 구현합니다.
	void FallDown(float dt);

};
