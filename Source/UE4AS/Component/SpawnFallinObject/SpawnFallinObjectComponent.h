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

	// ����� ���� Ȯ��
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true", ClampMin = 10.0, ClampMax = 90.0, UIMin = 10.0, UIMax = 90.0))
	float FishFallinPercentage;
	/// - meta : ��Ÿ������ ������
	/// - ClampMin, Max : �ش� �Ӽ��� ������ �� �ִ� �ּ�, �ִ� ���� �����մϴ�.
	///   ������ �ʰ��ϴ� ���� �����Ϳ��� �Է����� ��� ���� ���� ������ �����˴ϴ�.
	/// - UIMin, Max : �����̴��� ���Ͽ� ������ �� �ִ� ���� �ּ�, �ִ� ���� �����մϴ�.
	///   �����̴��� �����ϴ� ���� �ƴ�, ���� �Է��� ��� ������ �ʰ��� ���� �ԷµǾ ���� ���� ������ �������� �ʽ��ϴ�.
	/// - C++ �ڵ忡�� ���� �����ϴ� ��� ������ ���õ˴ϴ�.



public:	
	USpawnFallinObjectComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private :
	void InitializeDropObjectInfos();

	struct FFallinObjectInfo* GetRandomFallinObjectInfo(EFallinObjectType fallinObjType) const;


	// FallinObject �� �����ϴ� �޼���
	void CreateFallinObject();

		
};
