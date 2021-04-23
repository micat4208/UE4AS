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
	/// - VisibleAnywhere : �ش� �ʵ��� ���� �����Ϳ��� Ȯ���� �� �ֵ��� �մϴ�.
	/// - EditAnywhere : �ش� �ʵ��� ���� �����Ϳ��� ������ �� �ֵ��� �մϴ�.
	
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class URotatingMovementComponent* RotatingMovement;
	
	FFallinObjectInfo* FallinObjectInfo;

private:
	// �������� �ӷ��� ��Ÿ���ϴ�.
	float FallDownSpeed;

public:	
	AFallinObject();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public :
	// FallinObject �� �ʱ�ȭ�մϴ�.
	void InitializeFallinObject(FFallinObjectInfo* fallinObjInfo, float falldownSpeed);

private :
	// �������� �̵��� �����մϴ�.
	void FallDown(float dt);

};
