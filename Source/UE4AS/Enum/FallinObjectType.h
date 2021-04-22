#pragma once

#include "CoreMinimal.h"
#include "FallinObjectType.generated.h"

// 열거 형식을 선언합니다.
/// - BlueprintType : 블루 프린트에서도 사용 가능한 타입임을 명시합니다.
/// - Unreal C++ 에서 블루프린트에서 사용이 가능한 열거 형식을 선언하고자 하는 경우
///   BlueprintType 과 함께 언더라잉 타입을 uint8 형식으로 지정해야 합니다.
UENUM(BlueprintType)
enum class EFallinObjectType : uint8
{
	Trash  UMETA(DisplayName = 쓰레기),
	Fish   UMETA(DisplayName = 물고기)
};
// UMETA() 
/// - 클래스나 인터페이스, 구조체, 열거 형식, 열거 형식 요소, 함수, 속성 등의
///   동작하는 방식을 제어할 때 사용하는 메타 데이터 지정자
