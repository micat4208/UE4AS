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
	// 기반 형식의 BeginPlay() 메서드를 호출합니다.
	Super::BeginPlay();

	// 액터의 초기 위치를 저장합니다.
	ActorBeginLocation = GetOwner()->GetActorLocation();
	/// - GetOwner() : 이 컴포넌트를 소유하는 액터 객체를 얻습니다.
	/// - actorInstance->GetActorLocation() : actorInstance 의 월드 위치를 얻습니다.
}


void UFloatingMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	// 기반 형식의 TickComponent() 메서드를 호출합니다.
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FloatingMovement(DeltaTime);
}

void UFloatingMovementComponent::FloatingMovement(float dt)
{
	// 현재 액터의 초기 위치를 저장합니다.
	FVector newFloatingLocation = ActorBeginLocation;

	// 다음 Z 좌표 값을 설정합니다.
	newFloatingLocation.Z += FMath::Sin(
		(GetWorld()->TimeSeconds) * FloatingSpeed * dt) * FloatingValue;

	// 액터의 위치를 설정합니다.
	GetOwner()->SetActorLocation(newFloatingLocation);
	/// - actorInstance->SetActorLocation(newLocation) : actorInstance 의 위치를 newLocation 으로 설정합니다.


}

