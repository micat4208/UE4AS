#include "GamePlayerControllerBase.h"

void AGamePlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();

	// 카메라 뷰를 설정합니다.
	SetCameraView();
}

void AGamePlayerControllerBase::SetCameraView()
{

	TArray<AActor*> findActors;
	// 언리얼에서 제공하는 컨테이너
	/// - TArray<T> : 배열
	///   동적으로 크기를 조절할 수 있는 배열
	/// - TMap<Key, Value> : map
	///   키와 값이 함께 저장되며, 키는 중복 저장되지 않습니다.
	/// - TSet<> : 세트
	///   저장 순서가 유지되며, 중복 저장되지 않습니다.
	/// - TQueue<> : 큐
	/// - TStack<> : 스택

	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName(TEXT("Camera")), findActors);
	/// - UGameplayStatics : 유틸성 정적 메서드들을 제공하는 클래스입니다.
	/// - GetAllActorsWithTag(WorldContextObject, Tag, OutActors)
	///   Tag 와 일치하는 Tag 를 가진 액터를 월드에서 찾아 OutActors 에 저장합니다.
	///   WorldContextObject : World 객체를 전달합니다.
	
	SetViewTargetWithBlend(findActors[0]);
	/// SetViewTargetWithBlend(newViewTarget)
	/// - newViewTarget : 뷰 타깃을 newViewTarget 으로 설정합니다.
	
}
