#include "GamePlayerCharacter.h"

#include "Actor/PlayerController/GamePlayerControllerBase.h"

AGamePlayerCharacter::AGamePlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_BODY(
		TEXT("SkeletalMesh'/Game/Resources/Character/SK_Penguin.SK_Penguin'"));
	if (SK_BODY.Succeeded()) GetMesh()->SetSkeletalMesh(SK_BODY.Object);
	/// - ConstructorHelpers : �����ڿ��� Asset �� �ҷ����� �۾��� �����ִ� ����� �����ϴ� Ŭ����
	/// - FObjectFinder : Asset �� ���빰�� ������ ����
	/// - FClassFinder : Asset �� UClass �� ������ ����
	
	// Skeletal Mesh Component �� ����� ��ġ / ȸ���� �����մϴ�.
	//GetMesh()->SetRelativeLocation(FVector::UpVector * -88.0f);
	//GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	GetMesh()->SetRelativeLocationAndRotation(
		FVector::UpVector * -88.0f,
		FRotator(0.0f, -90.0f, 0.0f) );

}

void AGamePlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

}

void AGamePlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	PlayerController = Cast<AGamePlayerControllerBase>(NewController);
	/// Cast<T>(src) : src �� T �������� ĳ�����մϴ�.
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
	/// - ��� �α� â�� �α׸� ����ϴ� �Լ�
	/// - UE_LOG(ī�װ�, �α� ����, ����)
	///   - ī�װ� : �α��� ī�װ��� �����մϴ�.
	///   - �α� ���� : �α��� ������ ��Ÿ���ϴ�.
	///     Fatal : �α� ���ϰ� �ֿܼ� �׻� ��µǸ�, ���α׷��� ����˴ϴ�.
	///     Error : �������� �ְܼ� ���Ͽ� ��µ˴ϴ�.
	///     Warning : Ȳ������ �ְܼ� ���Ͽ� ����մϴ�.
	///     Log : ���Ͽ� ��µ˴ϴ�. �����Ϳ��� ������ ���� �ֿܼ��� ��µ˴ϴ�.
	///   - ���� : �α� ������ �ۼ��մϴ�.
	///     C ����� printf �� ���Ǵ� ���� �����ڸ� ����� �� �ֽ��ϴ�.
	
	AddMovementInput(FVector::RightVector, -axis);

	// PlayerController �� ��ȿ�� ��ü�� ����Ű���� Ȯ���մϴ�.
	if (IsValid(PlayerController))
	{
		// �÷��̾� ��Ʈ�ѷ��� ȸ����ŵ�ϴ�.
		PlayerController->SetControlRotation(
			FRotator(0.0f, 90.0f * -axis, 0.0f) );
	}
}

