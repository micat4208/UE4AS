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
	void InitialzieFallinObject(float falldownSpeed);

private :
	// 떨어지는 이동을 구현합니다.
	void FallDown(float dt);

};
