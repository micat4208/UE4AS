#pragma once

#include "EngineMinimal.h"


#ifndef CUSTOM_LOG_DEFINE
#define CUSTOM_LOG_DEFINE
#define LOG(_log_, ...) UE_LOG(LogTemp, Warning, _log_, ##__VA_ARGS__)

#endif

// Unreal Engine 은 Native C++ 과 다르게 리플렉션 시스템을 지원합니다.
/// - 리플렉션 시스템
///   - 프로그램이 실행 시간에 자기 자신을 조사할 수 있는 기능을 의미합니다.
///   - 언리얼에서는 자체적으로 class, structure, method, field, enumType 과 관련된 정보들을
///     수집이나 조작하는 시스템이 구축되어 있으며, 이러한 리플렉션 시스템을 Property System 이라고 합니다.
///   - Property System 은 Mecro 형태로 이루어져 있습니다.
///   - 이를 통해 GC 와 Blueprint 연동이 가능해집니다.
/// 
/// - 마크업 종류
///   - UENUM(), UCLASS(), USTRUCT(), UPROPERTY(), UFUNCTION()
///   - 이로 인해 프로퍼티 시스템을 사용할 수 있음!
/// 
/// - 특정한 형식에 Property System 을 지원하는 유형으로 마킹하는 방법
///   header 파일 include 구문 최하단에 #include "filename.generated.h" 작성
/// 
/// - UObject
/// - 언리얼 엔진의 관리를 받는 객체를 의미합니다.
/// 
/// - UHT (Unreal Header Tool)
///   UObject 를 지원하는 코드 생성 툴
///   헤더에서 클래스 선언을 UObject 규격에 맞게 선언하면 UHT 가 분석하여
///   Intermidiate 폴더에 UObject 정보를 담을 메타 파일을 생성함.
///   이 작업이 끝난 경우 본격적으로 컴파일을 진행하게 됩니다.
///   이러한 메타 정보들은 UClass 타입으로 보관되며 클래스 계층 구조 정보, 필드, 메서드 등을 기록합니다.
///   
/// - UObject 규격에 맞게 작성하여 UHT 의 도움을 받는 방법
///   - #include "filename.generated.h" 작성
///   - 마크업 작성 (ex : UCLASS())
///   - UObject 접두사 작성
///     (U, A, F, E, I)
///   - UObject 클래스나 UObject 클래스를 기반으로 두는 클래스 상속
///   - GENERATED_BODY(), GENERATED_USTRUCT_BODY() 작성
/// 
/// - C++ 객체가 UObject 가 되면 향상되는 기능
///   - 클래스 기본 객체 (Class Default Object) : 객체의 초기 값을 자체적으로 관리합니다.
///   - 리플렉션 : 런타임중 객체의 정보를 실시간으로 조회할 수 있습니다.
///   - 가비지 컬렉션(GC) : 참조되지 않은 힙의 객체를 해제합니다.
///   - 직렬화 (Serialization) : 객체와 속성 정보를 통째로 보관하며 로드합니다.
///   - 대리자 (Delegate) : 함수를 묶어서 효과적으로 관리하고 호출할 수 있습니다.
///   - Editor Intergration : Unreal 에디터 인터페이스를 통해 객체의 속성을 편집하고 확인할 수 있습니다.


// Unreal 이 권고하는 변수를 만들 때 언리얼에서 사용하는 자료형
/// - 정수 : 코어 데이터 형식을 사용합니다.
/// - int8           : __int8 
/// - int16          : __int16
/// - int32          : __int32
/// - int64          : __int64
/// - unsigned int8  : unsigned __int8 
/// - unsigned int16 : unsigned __int16
/// - unsigned int32 : unsigned __int32
/// - unsigned int64 : unsigned __int64
/// 
/// - TCHAR          : char / wchar_t
/// - FString, FName, FText - 문자열
/// - FString : 일반적인 문자열을 저장할 수 있는 타입
/// - FName : 어떠한 객체의 이름에 사용되는 타입
/// - FText : 현지화 가능 텍스트에 사용되는 타입
///           보통 UI 에 표시되는 문자열에 사용됩니다.
/// 
/// FName to String	: name.ToString()
/// FName to FText  : FText::FromName(name) 
/// - 변환 후 현지화가 불가능해질 수 있음.
/// 
/// FString to char * : *string
/// FString to FName : FName(*string)
/// - 대소문자를 구분하지 않게 됩니다.
/// FString to FText : FText::FromString(string)
/// - 변환 후 현지화가 불가능해질 수 있음.
/// 
/// FText to FString : text.ToString()
/// - 일부 언어에서 정상적으로 변환되지 않을 수 있음.
/// FText to FName : FName(*text.ToString())
/// - 일부 언어에서 정상적으로 변환되지 않을 수 있음.
///   변환 후 대소문자 구분 불가능

/// 언리얼 작명 규칙

// - 카멜 : 첫 글자를 소문자로, 다음에 오는 단어의 첫 글자는 대문자로 작성
//   ex) myVariable
// - 파스칼 : 단어 첫글자에 대분자를 사용하는 것은 카멜과 동일하지만, 첫 글자도 대문자로 작성
//   ex) MyVariable
// - 헝가리안 : 자료형에 따라 접두어가 달라집니다.
//   ex) bIsEnable
// - 스네이크 : 여러 단어로 이루어진 단어 사이를 언더바로 나누는 형식
//   ex) hello_world
