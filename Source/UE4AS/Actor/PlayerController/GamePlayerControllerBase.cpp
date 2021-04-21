#include "GamePlayerControllerBase.h"

void AGamePlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();

	// ī�޶� �並 �����մϴ�.
	SetCameraView();
}

void AGamePlayerControllerBase::SetCameraView()
{

	TArray<AActor*> findActors;
	// �𸮾󿡼� �����ϴ� �����̳�
	/// - TArray<T> : �迭
	///   �������� ũ�⸦ ������ �� �ִ� �迭
	/// - TMap<Key, Value> : map
	///   Ű�� ���� �Բ� ����Ǹ�, Ű�� �ߺ� ������� �ʽ��ϴ�.
	/// - TSet<> : ��Ʈ
	///   ���� ������ �����Ǹ�, �ߺ� ������� �ʽ��ϴ�.
	/// - TQueue<> : ť
	/// - TStack<> : ����

	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName(TEXT("Camera")), findActors);
	/// - UGameplayStatics : ��ƿ�� ���� �޼������ �����ϴ� Ŭ�����Դϴ�.
	/// - GetAllActorsWithTag(WorldContextObject, Tag, OutActors)
	///   Tag �� ��ġ�ϴ� Tag �� ���� ���͸� ���忡�� ã�� OutActors �� �����մϴ�.
	///   WorldContextObject : World ��ü�� �����մϴ�.
	
	SetViewTargetWithBlend(findActors[0]);
	/// SetViewTargetWithBlend(newViewTarget)
	/// - newViewTarget : �� Ÿ���� newViewTarget ���� �����մϴ�.
	
}
