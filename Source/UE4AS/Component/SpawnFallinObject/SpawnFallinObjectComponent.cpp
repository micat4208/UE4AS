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
	// DataTable 에서 행 이름들을 얻습니다.
	for (FName rowName : DT_FallinObjectInfo->GetRowNames())
	{
		// FindRow 를 이용하여 행 데이터를 찾을 때 문제가 생길 경우
		// 문제 내용을 알릴 문자열 변수를 나타냅니다.
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

	// 액터를 생성할 위치를 저장합니다.
	FVector spawnLocation = GetOwner()->GetActorLocation() + 
		(FMath::FRandRange(-1000.0f, 1000.0f) * FVector::RightVector);
	/// - GetOwner() : 해당 컴포넌트를 갖는 액터를 반환합니다.

	// 액터를 생성합니다.
	AFallinObject * newFallinObject = GetWorld()->SpawnActor<AFallinObject>(
		spawnLocation, FRotator::ZeroRotator);
	// SpawnActor<T>() : T 형식의 액터를 생성합니다.

	newFallinObject->InitializeFallinObject(
		GetRandomFallinObjectInfo(
		(FMath::FRandRange(1.0f, 100.0f) <= FishFallinPercentage) ? 
			EFallinObjectType::Fish : EFallinObjectType::Trash),
		FMath::FRandRange(600.0f, 800.0f)
	);

	// 타이머를 실행시킵니다.
	FTimerHandle timerHandle;
	FTimerDelegate timerDelegate;
	timerDelegate.BindUObject(this, &USpawnFallinObjectComponent::CreateFallinObject);
	GetWorld()->GetTimerManager().SetTimer(timerHandle, timerDelegate, CurrentDelay, false);
	/// - 타이머 : 정의한 시간마다 특정한 동작을 수행하는 기능을 의미합니다.

}

