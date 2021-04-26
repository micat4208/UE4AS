#include "SpawnFallinObjectComponent.h"

#include "Actor/FallinObject/FallinObject.h"

#include "Struct/FallinObjectInfo/FallinObjectInfo.h"

USpawnFallinObjectComponent::USpawnFallinObjectComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UDataTable>DT_FALLIN_OBJECT_INFO(
		TEXT("DataTable'/Game/Resources/Datatables/DT_FallinObjectInfo.DT_FallinObjectInfo'"));
	if (DT_FALLIN_OBJECT_INFO.Succeeded()) DT_FallinObjectInfo = DT_FALLIN_OBJECT_INFO.Object;
}

void USpawnFallinObjectComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentDelay = BeginDelay;

	InitializeDropObjectInfos();

	CreateFallinObject();
}

void USpawnFallinObjectComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (CurrentDelay > FinalDelay)
		CurrentDelay -= DeltaTime * 0.05f;

	else CurrentDelay = FinalDelay;
}

void USpawnFallinObjectComponent::InitializeDropObjectInfos()
{
	// DataTable ���� �� �̸����� ����ϴ�.
	for (FName rowName : DT_FallinObjectInfo->GetRowNames())
	{
		// FindRow �� �̿��Ͽ� �� �����͸� ã�� �� ������ ���� ���
		// ���� ������ �˸� ���ڿ� ������ ��Ÿ���ϴ�.
		FString contextStirng;
		FFallinObjectInfo* fallinObjectInfo = DT_FallinObjectInfo->FindRow<FFallinObjectInfo>(
			rowName, contextStirng);

		if (fallinObjectInfo->FallinObjectType == EFallinObjectType::Fish)
			FishObjectInfos.Add(fallinObjectInfo);
		else TrashObjectInfos.Add(fallinObjectInfo);
	}

}

FFallinObjectInfo* USpawnFallinObjectComponent::GetRandomFallinObjectInfo(EFallinObjectType fallinObjType) const
{
	TArray<FFallinObjectInfo*> targetArray = (fallinObjType == EFallinObjectType::Fish) ?
		FishObjectInfos : TrashObjectInfos;
	return targetArray[FMath::RandRange(0, targetArray.Num() - 1)];

	//if (fallinObjType == EFallinObjectType::Fish)
	//	return FishObjectInfos[FMath::RandRange(0, FishObjectInfos.Num() - 1)];
	//else return TrashObjectInfos[FMath::RandRange(0, TrashObjectInfos.Num() - 1)];
}

void USpawnFallinObjectComponent::CreateFallinObject()
{

	// ���͸� ������ ��ġ�� �����մϴ�.
	FVector spawnLocation = GetOwner()->GetActorLocation() + 
		(FMath::FRandRange(-1000.0f, 1000.0f) * FVector::RightVector);
	/// - GetOwner() : �ش� ������Ʈ�� ���� ���͸� ��ȯ�մϴ�.

	// ���͸� �����մϴ�.
	AFallinObject * newFallinObject = GetWorld()->SpawnActor<AFallinObject>(
		spawnLocation, FRotator::ZeroRotator);
	// SpawnActor<T>() : T ������ ���͸� �����մϴ�.

	newFallinObject->InitializeFallinObject(
		GetRandomFallinObjectInfo(
		(FMath::FRandRange(1.0f, 100.0f) <= FishFallinPercentage) ? 
			EFallinObjectType::Fish : EFallinObjectType::Trash),
		FMath::FRandRange(600.0f, 800.0f)
	);

	// Ÿ�̸Ӹ� �����ŵ�ϴ�.
	FTimerHandle timerHandle;
	FTimerDelegate timerDelegate;
	timerDelegate.BindUObject(this, &USpawnFallinObjectComponent::CreateFallinObject);
	GetWorld()->GetTimerManager().SetTimer(timerHandle, timerDelegate, CurrentDelay, false);
	/// - Ÿ�̸� : ������ �ð����� Ư���� ������ �����ϴ� ����� �ǹ��մϴ�.

}

