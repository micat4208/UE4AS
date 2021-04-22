#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Enum/FallinObjectType.h"
#include "FallinObjectInfo.generated.h"

// DataTable 에 사용되는 행 구조체를 선언할 경우
// - 프로퍼티 시스템이 이 구조체 형식을 등록합니다.
// - "Engine/DataTable.h" 를 포함
// - 구조체의 기반 형식을 FTableRowBase 형식으로 지정합니다.

// DataTable 을 사용할 때 주의할 점
/// - 백업 신경써서 하기
/// - 만약 사용되는 구조체에 멤버를 추가하는 경우
///   언리얼 에디터 종료 후 추가
///   구조체 멤버 추가 후 Visual Studio 에서 [Ctrl + F5] 에디터 실행


// 해당 구조체 형식을 프로퍼티 시스템에 등록합니다.
USTRUCT(BlueprintType)
struct UE4AS_API FFallinObjectInfo : 
	public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public :
	// FallinObject 타입
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "타입")
	EFallinObjectType DropObjectType;

	// FallinObject Mesh
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "기본")
	class UStaticMesh * Mesh;

	// Hp 변경 수치
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "기본")
	float ChangeHpValue;
};
