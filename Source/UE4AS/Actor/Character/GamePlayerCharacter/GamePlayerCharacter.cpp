#include "GamePlayerCharacter.h"

#include "Actor/PlayerController/GamePlayerControllerBase.h"

#include "AnimInstance/PlayerCharacterAnimInstance.h"

AGamePlayerCharacter::AGamePlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FClassFinder<UPlayerCharacterAnimInstance> BP_PLAYER_CHAR_ANIM_INST(
		TEXT("AnimBlueprint'/Game/Blueprints/AnimInstances/BP_PlayerCharacterAnimInstance.BP_PlayerCharacterAnimInstance_C'"));
	if (BP_PLAYER_CHAR_ANIM_INST.Succeeded()) BP_PlayerCharacterAnimInstance = BP_PLAYER_CHAR_ANIM_INST.Class;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_BODY(
		TEXT("SkeletalMesh'/Game/Resources/Character/SK_Penguin.SK_Penguin'"));
	if (SK_BODY.Succeeded()) GetMesh()->SetSkeletalMesh(SK_BODY.Object);
	/// - ConstructorHelpers : 생성자에서 Asset 을 불러오는 작업을 도와주는 기능을 제공하는 클래스
	/// - FObjectFinder : Asset 의 내용물을 얻어오는 형식
	/// - FClassFinder : Asset 의 UClass 을 얻어오는 형식
	///   경로의 끝에 _C 를 작성합니다.
	
	// Skeletal Mesh Component 의 상대적 위치 / 회전을 설정합니다.
	//GetMesh()->SetRelativeLocation(FVector::UpVector * -88.0f);
	//GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	GetMesh()->SetRelativeLocationAndRotation(
		FVector::UpVector * -88.0f,
		FRotator(0.0f, -90.0f, 0.0f) );

	// Anim Instance 클래스 등록
	GetMesh()->SetAnimInstanceClass(BP_PlayerCharacterAnimInstance);

}

void AGamePlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

}

void AGamePlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	PlayerController = Cast<AGamePlayerControllerBase>(NewController);
	/// Cast<T>(src) : src 를 T 형식으로 캐스팅합니다.
}

void AGamePlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGamePlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &AGamePlayerCharacter::InputHorizontal);

}

void AGamePlayerCharacter::InputHorizontal(float axis)
{
	//UE_LOG(LogTemp, Warning, TEXT("axis = %.2f"), axis);
	/// - 출력 로그 창에 로그를 출력하는 함수
	/// - UE_LOG(카테고리, 로그 레벨, 내용)
	///   - 카테고리 : 로그의 카테고리를 지정합니다.
	///   - 로그 레벨 : 로그의 수준을 나타냅니다.
	///     Fatal : 로그 파일과 콘솔에 항상 출력되며, 프로그램이 종료됩니다.
	///     Error : 적색으로 콘솔과 파일에 출력됩니다.
	///     Warning : 황색으로 콘솔과 파일에 출력합니다.
	///     Log : 파일에 출력됩니다. 에디터에서 실행할 때는 콘솔에도 출력됩니다.
	///   - 내용 : 로그 내용을 작성합니다.
	///     C 언어의 printf 에 사용되는 서식 지정자를 사용할 수 있습니다.
	
	AddMovementInput(FVector::RightVector, -axis);

	// PlayerController 가 유효한 객체를 가리키는지 확인합니다.
	if (IsValid(PlayerController))
	{
		// 플레이어 컨트롤러를 회전시킵니다.
		PlayerController->SetControlRotation(
			FRotator(0.0f, 90.0f * -axis, 0.0f) );
	}
}

