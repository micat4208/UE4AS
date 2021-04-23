#include "FallinObject.h"

#include "GameFramework/RotatingMovementComponent.h"

AFallinObject::AFallinObject()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("STATIC_MESH"));
	RotatingMovement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("ROTATING_MOVEMENT"));

	// StaticMeshComponent 를 RootComponent 로 설정합니다.
	/// - RootComponent : 액터를 대표하는 컴포넌트를 의미하며, 
	///   액터에 단 하나만 설정될 수 있습니다.
	/// - 루트 컴포넌트를 설정할 때 : SetRootComponent()
	/// - 루트 컴포넌트를 외부에서 얻어올 때 : GetRootComponent()
	SetRootComponent(Mesh);

	// 생성된 StaticMeshComponent 를 RootComponent 에 부착합니다.
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

	// 물고기는 회전시키지 않습니다.
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

