#include "FallinObject.h"

AFallinObject::AFallinObject()
{
	PrimaryActorTick.bCanEverTick = true;
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

void AFallinObject::InitialzieFallinObject(float falldownSpeed)
{
	FallDownSpeed = falldownSpeed;
}

void AFallinObject::FallDown(float dt)
{
	FVector currentLocation = GetActorLocation();
	FVector newLocation = currentLocation + FVector::DownVector * FallDownSpeed;


}

