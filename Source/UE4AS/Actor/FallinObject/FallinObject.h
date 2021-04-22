#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FallinObject.generated.h"

UCLASS()
class UE4AS_API AFallinObject final : 
	public AActor
{
	GENERATED_BODY()

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
	void InitialzieFallinObject(float falldownSpeed);

private :
	// �������� �̵��� �����մϴ�.
	void FallDown(float dt);

};
