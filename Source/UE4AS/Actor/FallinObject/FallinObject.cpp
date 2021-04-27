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

	// StaticMeshComponent 와 어떠한 액터가 겹쳤을 경우 호출시킬 메서드를 바인딩시킵니다.
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

	// Static Mesh 애셋 설정
	Mesh->SetStaticMesh(FallinObjectInfo->Mesh);

	// Static Mesh Component 의 컬리전 프로파일을 다른 컬리전과 겹칠수 있는 상태로 설정합니다.
	Mesh->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
		
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

	if (newLocation.Z < -250.0f)
	{
		// 액터를 제거합니다.
		Destroy();
		/// - 자기 자신을 제거할 때 사용합니다.

		//GetWorld()->DestroyActor(this);
		/// - 다른 액터를 제거할 때 사용합니다.
	}

	SetActorLocation(newLocation);

	

}

void AFallinObject::OnOverlapped(
	UPrimitiveComponent*	OverlappedComponent, /// - 겹친 자신의 컴포넌트가 전달됩니다.
	AActor*					OtherActor, 		 /// - 겹친 상대 액터가 전달됩니다.
	UPrimitiveComponent*	OtherComp, 			 /// - 겹친 상대 컴포넌트가 전달됩니다.
	int32					OtherBodyIndex, 	 /// - bMultiBodyOverlap 속성이 true 인경우 여러 컬리전과 겹쳤을 경우 컬리전을 구분하기 위한 번호가 전달됩니다.
	bool					bFromSweep, 		 /// - 액터가 이동할 때 Sweep 이벤트를 발생시키도록 하여 발생한 이벤트인지가 전달됩니다.
	const FHitResult&		SweepResult)		 /// - Sweep 이벤트 발생 시 자세한 결과를 담고 있는 데이터가 전달됩니다.
{
	if (IsValid(OtherActor))
	{
		UE_LOG(LogTemp, Warning, TEXT("OtherActor->Name : %s"), *OtherActor->GetFName().ToString());
	}

}

