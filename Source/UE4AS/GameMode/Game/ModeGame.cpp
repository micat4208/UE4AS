#include "ModeGame.h"

#include "Actor/Character/GamePlayerCharacter/GamePlayerCharacter.h"
#include "Actor/PlayerController/GamePlayerController/GamePlayerController.h"

AModeGame::AModeGame()
{
	// 기본적으로 사용될 Pawn Class 를 설정합니다.
	DefaultPawnClass = AGamePlayerCharacter::StaticClass();
	/// TSubclassOf<Type> : Type 과 상속 관계에 있는 UClass 를 가리킬 수 있는 타입
	/// UClass * : 모든 UClass 를 가리킬 수 있는 타입
	/// Type::StaticClass() : Type 의 UClass 를 얻습니다.
	
	// 사용할 플레이어 컨트롤러를 설정합니다.
	PlayerControllerClass = AGamePlayerController::StaticClass();
}