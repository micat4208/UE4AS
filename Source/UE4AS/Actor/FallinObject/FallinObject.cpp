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

	// StaticMeshComponent �� ��� ���Ͱ� ������ ��� ȣ���ų �޼��带 ���ε���ŵ�ϴ�.
	Mesh->OnComponentBeginOverlap.AddDynamic(this, &AFallinObject::OnOverlapped);
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

	// Static Mesh �ּ� ����
	Mesh->SetStaticMesh(FallinObjectInfo->Mesh);

	// Static Mesh Component �� �ø��� ���������� �ٸ� �ø����� ��ĥ�� �ִ� ���·� �����մϴ�.
	Mesh->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
		
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

	if (newLocation.Z < -250.0f)
	{
		// ���͸� �����մϴ�.
		Destroy();
		/// - �ڱ� �ڽ��� ������ �� ����մϴ�.

		//GetWorld()->DestroyActor(this);
		/// - �ٸ� ���͸� ������ �� ����մϴ�.
	}

	SetActorLocation(newLocation);

	

}

void AFallinObject::OnOverlapped(
	UPrimitiveComponent*	OverlappedComponent, /// - ��ģ �ڽ��� ������Ʈ�� ���޵˴ϴ�.
	AActor*					OtherActor, 		 /// - ��ģ ��� ���Ͱ� ���޵˴ϴ�.
	UPrimitiveComponent*	OtherComp, 			 /// - ��ģ ��� ������Ʈ�� ���޵˴ϴ�.
	int32					OtherBodyIndex, 	 /// - bMultiBodyOverlap �Ӽ��� true �ΰ�� ���� �ø����� ������ ��� �ø����� �����ϱ� ���� ��ȣ�� ���޵˴ϴ�.
	bool					bFromSweep, 		 /// - ���Ͱ� �̵��� �� Sweep �̺�Ʈ�� �߻���Ű���� �Ͽ� �߻��� �̺�Ʈ������ ���޵˴ϴ�.
	const FHitResult&		SweepResult)		 /// - Sweep �̺�Ʈ �߻� �� �ڼ��� ����� ��� �ִ� �����Ͱ� ���޵˴ϴ�.
{
	if (IsValid(OtherActor))
	{
		UE_LOG(LogTemp, Warning, TEXT("OtherActor->Name : %s"), *OtherActor->GetFName().ToString());
	}

}

