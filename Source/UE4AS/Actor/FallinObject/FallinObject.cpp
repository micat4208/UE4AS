#include "FallinObject.h"

#include "GameFramework/RotatingMovementComponent.h"

AFallinObject::AFallinObject()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("STATIC_MESH"));
	RotatingMovement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("ROTATING_MOVEMENT"));

	// StaticMeshComponent �� RootComponent �� �����մϴ�.
	/// - RootComponent : ���͸� ��ǥ�ϴ� ������Ʈ�� �ǹ��ϸ�, 
	///   ���Ϳ� �� �ϳ��� ������ �� �ֽ��ϴ�.
	/// - ��Ʈ ������Ʈ�� ������ �� : SetRootComponent()
	/// - ��Ʈ ������Ʈ�� �ܺο��� ���� �� : GetRootComponent()
	SetRootComponent(Mesh);

	// ������ StaticMeshComponent �� RootComponent �� �����մϴ�.
	//Mesh->SetupAttachment(GetRootComponent());
}

void AFallinObject::BeginPlay()
{
	Super::BeginPlay();
}

void AFallinObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FallDown(DeltaTime);
}

void AFallinObject::InitializeFallinObject(FFallinObjectInfo* fallinObjInfo, float falldownSpeed)
{
	FallinObjectInfo = fallinObjInfo;
	FallDownSpeed = falldownSpeed;

	Mesh->SetStaticMesh(FallinObjectInfo->Mesh);

	// ������ ȸ����Ű�� �ʽ��ϴ�.
	RotatingMovement->RotationRate =
		(FallinObjectInfo->FallinObjectType == EFallinObjectType::Fish) ?
		FRotator::ZeroRotator :
		FRotator(0.0f, 0.0f, -180.0f);
}

void AFallinObject::FallDown(float dt)
{
	FVector currentLocation = GetActorLocation();
	FVector newLocation = currentLocation + FVector::DownVector * (FallDownSpeed * dt);

	SetActorLocation(newLocation);

}

