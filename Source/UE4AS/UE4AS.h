#pragma once

#include "EngineMinimal.h"


#ifndef CUSTOM_LOG_DEFINE
#define CUSTOM_LOG_DEFINE
#define LOG(_log_, ...) UE_LOG(LogTemp, Warning, _log_, ##__VA_ARGS__)

#endif

// Unreal Engine �� Native C++ �� �ٸ��� ���÷��� �ý����� �����մϴ�.
/// - ���÷��� �ý���
///   - ���α׷��� ���� �ð��� �ڱ� �ڽ��� ������ �� �ִ� ����� �ǹ��մϴ�.
///   - �𸮾󿡼��� ��ü������ class, structure, method, field, enumType �� ���õ� ��������
///     �����̳� �����ϴ� �ý����� ����Ǿ� ������, �̷��� ���÷��� �ý����� Property System �̶�� �մϴ�.
///   - Property System �� Mecro ���·� �̷���� �ֽ��ϴ�.
///   - �̸� ���� GC �� Blueprint ������ ���������ϴ�.
/// 
/// - ��ũ�� ����
///   - UENUM(), UCLASS(), USTRUCT(), UPROPERTY(), UFUNCTION()
///   - �̷� ���� ������Ƽ �ý����� ����� �� ����!
/// 
/// - Ư���� ���Ŀ� Property System �� �����ϴ� �������� ��ŷ�ϴ� ���
///   header ���� include ���� ���ϴܿ� #include "filename.generated.h" �ۼ�
/// 
/// - UObject
/// - �𸮾� ������ ������ �޴� ��ü�� �ǹ��մϴ�.
/// 
/// - UHT (Unreal Header Tool)
///   UObject �� �����ϴ� �ڵ� ���� ��
///   ������� Ŭ���� ������ UObject �԰ݿ� �°� �����ϸ� UHT �� �м��Ͽ�
///   Intermidiate ������ UObject ������ ���� ��Ÿ ������ ������.
///   �� �۾��� ���� ��� ���������� �������� �����ϰ� �˴ϴ�.
///   �̷��� ��Ÿ �������� UClass Ÿ������ �����Ǹ� Ŭ���� ���� ���� ����, �ʵ�, �޼��� ���� ����մϴ�.
///   
/// - UObject �԰ݿ� �°� �ۼ��Ͽ� UHT �� ������ �޴� ���
///   - #include "filename.generated.h" �ۼ�
///   - ��ũ�� �ۼ� (ex : UCLASS())
///   - UObject ���λ� �ۼ�
///     (U, A, F, E, I)
///   - UObject Ŭ������ UObject Ŭ������ ������� �δ� Ŭ���� ���
///   - GENERATED_BODY(), GENERATED_USTRUCT_BODY() �ۼ�
/// 
/// - C++ ��ü�� UObject �� �Ǹ� ���Ǵ� ���
///   - Ŭ���� �⺻ ��ü (Class Default Object) : ��ü�� �ʱ� ���� ��ü������ �����մϴ�.
///   - ���÷��� : ��Ÿ���� ��ü�� ������ �ǽð����� ��ȸ�� �� �ֽ��ϴ�.
///   - ������ �÷���(GC) : �������� ���� ���� ��ü�� �����մϴ�.
///   - ����ȭ (Serialization) : ��ü�� �Ӽ� ������ ��°�� �����ϸ� �ε��մϴ�.
///   - �븮�� (Delegate) : �Լ��� ��� ȿ�������� �����ϰ� ȣ���� �� �ֽ��ϴ�.
///   - Editor Intergration : Unreal ������ �������̽��� ���� ��ü�� �Ӽ��� �����ϰ� Ȯ���� �� �ֽ��ϴ�.


// Unreal �� �ǰ��ϴ� ������ ���� �� �𸮾󿡼� ����ϴ� �ڷ���
/// - ���� : �ھ� ������ ������ ����մϴ�.
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
/// - FString, FName, FText - ���ڿ�
/// - FString : �Ϲ����� ���ڿ��� ������ �� �ִ� Ÿ��
/// - FName : ��� ��ü�� �̸��� ���Ǵ� Ÿ��
/// - FText : ����ȭ ���� �ؽ�Ʈ�� ���Ǵ� Ÿ��
///           ���� UI �� ǥ�õǴ� ���ڿ��� ���˴ϴ�.
/// 
/// FName to String	: name.ToString()
/// FName to FText  : FText::FromName(name) 
/// - ��ȯ �� ����ȭ�� �Ұ������� �� ����.
/// 
/// FString to char * : *string
/// FString to FName : FName(*string)
/// - ��ҹ��ڸ� �������� �ʰ� �˴ϴ�.
/// FString to FText : FText::FromString(string)
/// - ��ȯ �� ����ȭ�� �Ұ������� �� ����.
/// 
/// FText to FString : text.ToString()
/// - �Ϻ� ���� ���������� ��ȯ���� ���� �� ����.
/// FText to FName : FName(*text.ToString())
/// - �Ϻ� ���� ���������� ��ȯ���� ���� �� ����.
///   ��ȯ �� ��ҹ��� ���� �Ұ���

/// �𸮾� �۸� ��Ģ

// - ī�� : ù ���ڸ� �ҹ��ڷ�, ������ ���� �ܾ��� ù ���ڴ� �빮�ڷ� �ۼ�
//   ex) myVariable
// - �Ľ�Į : �ܾ� ù���ڿ� ����ڸ� ����ϴ� ���� ī��� ����������, ù ���ڵ� �빮�ڷ� �ۼ�
//   ex) MyVariable
// - �밡���� : �ڷ����� ���� ���ξ �޶����ϴ�.
//   ex) bIsEnable
// - ������ũ : ���� �ܾ�� �̷���� �ܾ� ���̸� ����ٷ� ������ ����
//   ex) hello_world
