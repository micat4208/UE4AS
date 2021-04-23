#pragma once

#include "UE4AS.h"
#include "Components/ActorComponent.h"
#include "Enum/FallinObjectType.h"
#include "SpawnFallinObjectComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE4AS_API USpawnFallinObjectComponent : public UActorComponent
{
	GENERATED_BODY()

private :
	class UDataTable* DT_FallinObjectInfo;

private :
	TArray<struct FFallinObjectInfo*> FishObjectInfos;
	TArray<struct FFallinObjectInfo*> TrashObjectInfos;

	// 물고기 생성 확률
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true", ClampMin = 10.0, ClampMax = 90.0, UIMin = 10.0, UIMax = 90.0))
	float FishFallinPercentage;
	/// - meta : 메타데이터 지정자
	/// - ClampMin, Max : 해당 속성에 설정할 수 있는 최소, 최대 값을 지정합니다.
	///   범위를 초과하는 값을 에디터에서 입력했을 경우 범위 내의 값으로 설정됩니다.
	/// - UIMin, Max : 슬라이더를 통하여 설정할 수 있는 값의 최소, 최대 값을 지정합니다.
	///   슬라이더를 조종하는 것이 아닌, 값을 입력할 경우 범위를 초과한 값이 입력되어도 범위 내의 값으로 설정되지 않습니다.
	/// - C++ 코드에서 값을 제어하는 경우 범위는 무시됩니다.



public:	
	USpawnFallinObjectComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private :
	void InitializeDropObjectInfos();

	struct FFallinObjectInfo* GetRandomFallinObjectInfo(EFallinObjectType fallinObjType) const;


	// FallinObject 를 생성하는 메서드
	void CreateFallinObject();

		
};
