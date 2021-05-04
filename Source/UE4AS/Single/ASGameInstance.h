#pragma once

#include "CoreMinimal.h"

#include "Engine/GameInstance.h"

#include "Serialization/JsonWriter.h"
#include "JsonObjectConverter.h"


#include "ASGameInstance.generated.h"

// 게임 전체를 관리합니다.
UCLASS()
class UE4AS_API UASGameInstance final : 
	public UGameInstance
{
	GENERATED_BODY()

private :
	// 게임 플레이 상태를 나타냅니다.
	bool bIsPlaying;

	// 현재 점수를 나타냅니다.
	float CurrentScore;

public :
	// GameInstance 가 생성된 이후 단 한번 호출되는 메서드입니다.
	virtual void Init() override;

public :
	// 현재 점수를 반환합니다.
	FORCEINLINE float GetCurrentScore() const
	{ return CurrentScore; }

	// 점수를 리셋시킵니다.
	FORCEINLINE void ResetCurrentScore()
	{ CurrentScore = 0.0f; }

	// 점수를 더합니다.
	FORCEINLINE void AddCurrentScore(float addScore)
	{ if (bIsPlaying) CurrentScore += addScore; }
	
	// 게임 플레이 상태를 나타냅니다.
	FORCEINLINE bool IsPlaying() const
	{ return bIsPlaying; }

	// 게임 시작
	FORCEINLINE void StartGame()
	{ bIsPlaying = true; }

	// 게임 끝
	FORCEINLINE void EndGame()
	{ bIsPlaying = false; }

public :
	// 최고 점수 갱신을 시도합니다.
	void TryUpdateBestScore();

public :

	// Json 파일을 저장합니다.
	template<typename T>
	void SaveJson(FString fileName, T& saveData, FString keyName = FString(TEXT("default")))
	{
		// 파일이 저장될 폴더 경로
		FString folderPath = FPaths::GameDir() + TEXT("/Content/Resources/Json/SaveData");
		/// - FPaths : 게임, 엔진의 경로 등을 검색하기 위한 기능을 제공하는 클래스
		/// - GameDir() : 게임 경로를 나타냅니다.

		// 경로가 존재하지 않는다면 경로 생성
		if (!FPlatformFileManager::Get().GetPlatformFile().DirectoryExists(*folderPath))
			FPlatformFileManager::Get().GetPlatformFile().CreateDirectory(*folderPath);

		// Json 파일에 저장할 데이터(saveData) 를 문자열로 변환시킵니다.
		FString serializedData;
		FJsonObjectConverter::UStructToJsonObjectString(saveData, serializedData);
		/// - FJsonObjectConverter : Json 객체와 UStruct 간의 변환에 대한 기능을 제공하는 클래스
		/// - UStructToJsonObjectString() : UStruct 에서 Json 문자열로 변환시켜주는 정적 메서드.
		
		// Json 오브젝트를 생성합니다.
		FString jsonStr;
		auto jsonObj = TJsonWriterFactory<>::Create(&jsonStr);
		/// - TJsonWrite 객체를 생성합니다.
		/// - TJsonWrite : Json 파일 쓰기에 대한 내용을 제공하는 클래스

		jsonObj->WriteObjectStart();
		/// - Json 데이터는 중괄호를 통해 나누어져 있고, 키 : 내용 으로 구분되어 있음.
		/// - 이때 Key 는 String, 내용으로는 Boolean, Integer, Single, String 타입으로 저장할 수 있다.
		/// - WriteObjectStart() : 중괄호를 펼쳐 Json 파일의 오브젝트를 나누는 역할을 하며,
		///   최초의 중괄호는 항상 필요하기 때문에 작성되었음.
		/// - 오브젝트를 구분하고 싶다면 WriteObjectStart() ~ WriteObjectEnd() 로 구분시키면 됩니다.
		/// - 데이터 입력이 끝난다면 Close() 메서드를 호출하여 Json 데이터 입력 끝을 알려야 합니다.
		
		// 데이터 쓰기
		jsonObj->WriteValue(keyName, serializedData);

		// Json 오브젝트 끝
		jsonObj->WriteObjectEnd();

		// 데이터 입력 끝
		jsonObj->Close();

		// 저장될 파일 경로를 완성합니다.
		folderPath += FString(TEXT("/")) + fileName + FString(TEXT(".json"));

		// 파일 저장
		FFileHelper::SaveStringToFile(*jsonStr, *folderPath);
	}

	template<typename T>
	bool LoadJson(FString fileName, T& outResult, FString keyName = FString(TEXT("default")))
	{
		// 파일이 저장된 폴더 경로
		FString folderPath = FPaths::GameDir() + TEXT("/Content/Resources/Json/SaveData");

		// 경로가 존재하지 않는다면 로드 실패
		if (!FPlatformFileManager::Get().GetPlatformFile().DirectoryExists(*folderPath))
			return false;

		folderPath += FString(TEXT("/")) + fileName + FString(TEXT(".json"));

		// 파일을 읽어옵니다.
		/// - 만약 파일을 읽지 못했을 경우 로드 실패
		FString jsonStr;
		if (!FFileHelper::LoadFileToString(jsonStr, *folderPath))
			return false;

		// Json 파일을 읽을 객체 생성
		auto reader = TJsonReaderFactory<TCHAR>::Create(jsonStr);

		// json 오브젝트 생성
		TSharedPtr<FJsonObject> jsonObj = MakeShareable(new FJsonObject());

		// 역직렬화하여 원하는 데이터를 얻습니다.
		bool completed = FJsonSerializer::Deserialize(reader, jsonObj);

		// 역직렬화에 성공했다면
		if (completed)
		{
			// 저장할 때 입력했던 key 를 이용하여 outResult 에 읽어온 값을 저장합니다.
			FJsonObjectConverter::JsonObjectStringToUStruct(
				(jsonObj->GetStringField(keyName)), &outResult, 0, 0);

			// 로드 성공
			return true;
		}

		// 실패했다면
		return false;
	}




};
