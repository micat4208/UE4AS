#pragma once

#include "CoreMinimal.h"

#include "Engine/GameInstance.h"

#include "Serialization/JsonWriter.h"
#include "JsonObjectConverter.h"


#include "ASGameInstance.generated.h"

// ���� ��ü�� �����մϴ�.
UCLASS()
class UE4AS_API UASGameInstance final : 
	public UGameInstance
{
	GENERATED_BODY()

private :
	// ���� �÷��� ���¸� ��Ÿ���ϴ�.
	bool bIsPlaying;

	// ���� ������ ��Ÿ���ϴ�.
	float CurrentScore;

public :
	// GameInstance �� ������ ���� �� �ѹ� ȣ��Ǵ� �޼����Դϴ�.
	virtual void Init() override;

public :
	// ���� ������ ��ȯ�մϴ�.
	FORCEINLINE float GetCurrentScore() const
	{ return CurrentScore; }

	// ������ ���½�ŵ�ϴ�.
	FORCEINLINE void ResetCurrentScore()
	{ CurrentScore = 0.0f; }

	// ������ ���մϴ�.
	FORCEINLINE void AddCurrentScore(float addScore)
	{ if (bIsPlaying) CurrentScore += addScore; }
	
	// ���� �÷��� ���¸� ��Ÿ���ϴ�.
	FORCEINLINE bool IsPlaying() const
	{ return bIsPlaying; }

	// ���� ����
	FORCEINLINE void StartGame()
	{ bIsPlaying = true; }

	// ���� ��
	FORCEINLINE void EndGame()
	{ bIsPlaying = false; }

public :
	// �ְ� ���� ������ �õ��մϴ�.
	void TryUpdateBestScore();

public :

	// Json ������ �����մϴ�.
	template<typename T>
	void SaveJson(FString fileName, T& saveData, FString keyName = FString(TEXT("default")))
	{
		// ������ ����� ���� ���
		FString folderPath = FPaths::GameDir() + TEXT("/Content/Resources/Json/SaveData");
		/// - FPaths : ����, ������ ��� ���� �˻��ϱ� ���� ����� �����ϴ� Ŭ����
		/// - GameDir() : ���� ��θ� ��Ÿ���ϴ�.

		// ��ΰ� �������� �ʴ´ٸ� ��� ����
		if (!FPlatformFileManager::Get().GetPlatformFile().DirectoryExists(*folderPath))
			FPlatformFileManager::Get().GetPlatformFile().CreateDirectory(*folderPath);

		// Json ���Ͽ� ������ ������(saveData) �� ���ڿ��� ��ȯ��ŵ�ϴ�.
		FString serializedData;
		FJsonObjectConverter::UStructToJsonObjectString(saveData, serializedData);
		/// - FJsonObjectConverter : Json ��ü�� UStruct ���� ��ȯ�� ���� ����� �����ϴ� Ŭ����
		/// - UStructToJsonObjectString() : UStruct ���� Json ���ڿ��� ��ȯ�����ִ� ���� �޼���.
		
		// Json ������Ʈ�� �����մϴ�.
		FString jsonStr;
		auto jsonObj = TJsonWriterFactory<>::Create(&jsonStr);
		/// - TJsonWrite ��ü�� �����մϴ�.
		/// - TJsonWrite : Json ���� ���⿡ ���� ������ �����ϴ� Ŭ����

		jsonObj->WriteObjectStart();
		/// - Json �����ʹ� �߰�ȣ�� ���� �������� �ְ�, Ű : ���� ���� ���еǾ� ����.
		/// - �̶� Key �� String, �������δ� Boolean, Integer, Single, String Ÿ������ ������ �� �ִ�.
		/// - WriteObjectStart() : �߰�ȣ�� ���� Json ������ ������Ʈ�� ������ ������ �ϸ�,
		///   ������ �߰�ȣ�� �׻� �ʿ��ϱ� ������ �ۼ��Ǿ���.
		/// - ������Ʈ�� �����ϰ� �ʹٸ� WriteObjectStart() ~ WriteObjectEnd() �� ���н�Ű�� �˴ϴ�.
		/// - ������ �Է��� �����ٸ� Close() �޼��带 ȣ���Ͽ� Json ������ �Է� ���� �˷��� �մϴ�.
		
		// ������ ����
		jsonObj->WriteValue(keyName, serializedData);

		// Json ������Ʈ ��
		jsonObj->WriteObjectEnd();

		// ������ �Է� ��
		jsonObj->Close();

		// ����� ���� ��θ� �ϼ��մϴ�.
		folderPath += FString(TEXT("/")) + fileName + FString(TEXT(".json"));

		// ���� ����
		FFileHelper::SaveStringToFile(*jsonStr, *folderPath);
	}

	template<typename T>
	bool LoadJson(FString fileName, T& outResult, FString keyName = FString(TEXT("default")))
	{
		// ������ ����� ���� ���
		FString folderPath = FPaths::GameDir() + TEXT("/Content/Resources/Json/SaveData");

		// ��ΰ� �������� �ʴ´ٸ� �ε� ����
		if (!FPlatformFileManager::Get().GetPlatformFile().DirectoryExists(*folderPath))
			return false;

		folderPath += FString(TEXT("/")) + fileName + FString(TEXT(".json"));

		// ������ �о�ɴϴ�.
		/// - ���� ������ ���� ������ ��� �ε� ����
		FString jsonStr;
		if (!FFileHelper::LoadFileToString(jsonStr, *folderPath))
			return false;

		// Json ������ ���� ��ü ����
		auto reader = TJsonReaderFactory<TCHAR>::Create(jsonStr);

		// json ������Ʈ ����
		TSharedPtr<FJsonObject> jsonObj = MakeShareable(new FJsonObject());

		// ������ȭ�Ͽ� ���ϴ� �����͸� ����ϴ�.
		bool completed = FJsonSerializer::Deserialize(reader, jsonObj);

		// ������ȭ�� �����ߴٸ�
		if (completed)
		{
			// ������ �� �Է��ߴ� key �� �̿��Ͽ� outResult �� �о�� ���� �����մϴ�.
			FJsonObjectConverter::JsonObjectStringToUStruct(
				(jsonObj->GetStringField(keyName)), &outResult, 0, 0);

			// �ε� ����
			return true;
		}

		// �����ߴٸ�
		return false;
	}




};
