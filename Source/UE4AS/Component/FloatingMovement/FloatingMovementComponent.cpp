// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingMovementComponent.h"

// Sets default values for this component's properties
UFloatingMovementComponent::UFloatingMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UFloatingMovementComponent::BeginPlay()
{
	// ��� ������ BeginPlay() �޼��带 ȣ���մϴ�.
	Super::BeginPlay();

	// ������ �ʱ� ��ġ�� �����մϴ�.
	ActorBeginLocation = GetOwner()->GetActorLocation();
	/// - GetOwner() : �� ������Ʈ�� �����ϴ� ���� ��ü�� ����ϴ�.
	/// - actorInstance->GetActorLocation() : actorInstance �� ���� ��ġ�� ����ϴ�.
}


void UFloatingMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	// ��� ������ TickComponent() �޼��带 ȣ���մϴ�.
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FloatingMovement(DeltaTime);
}

void UFloatingMovementComponent::FloatingMovement(float dt)
{
	// ���� ������ �ʱ� ��ġ�� �����մϴ�.
	FVector newFloatingLocation = ActorBeginLocation;

	// ���� Z ��ǥ ���� �����մϴ�.
	newFloatingLocation.Z += FMath::Sin(
		(GetWorld()->TimeSeconds) * FloatingSpeed * dt) * FloatingValue;

	// ������ ��ġ�� �����մϴ�.
	GetOwner()->SetActorLocation(newFloatingLocation);
	/// - actorInstance->SetActorLocation(newLocation) : actorInstance �� ��ġ�� newLocation ���� �����մϴ�.


}

