#include "GamePlayerCharacter.h"

AGamePlayerCharacter::AGamePlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_BODY(
		TEXT("SkeletalMesh'/Game/Resources/Character/SK_Penguin.SK_Penguin'"));
	if (SK_BODY.Succeeded()) GetMesh()->SetSkeletalMesh(SK_BODY.Object);

	/// - ConstructorHelpers : �����ڿ��� Asset �� �ҷ����� �۾��� �����ִ� ����� �����ϴ� Ŭ����
	/// - FObjectFinder : Asset �� ���빰�� ������ ����
	/// - FClassFinder : Asset �� UClass �� ������ ����

}

void AGamePlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

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
	UE_LOG(LogTemp, Warning, TEXT("axis = %.2f"), axis);
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

}

