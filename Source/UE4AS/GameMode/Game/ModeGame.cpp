#include "ModeGame.h"

#include "Actor/Character/GamePlayerCharacter/GamePlayerCharacter.h"
#include "Actor/PlayerController/GamePlayerControllerBase.h"

AModeGame::AModeGame()
{
	// �⺻������ ���� Pawn Class �� �����մϴ�.
	DefaultPawnClass = AGamePlayerCharacter::StaticClass();
	/// TSubclassOf<Type> : Type �� ��� ���迡 �ִ� UClass �� ����ų �� �ִ� Ÿ��
	/// UClass * : ��� UClass �� ����ų �� �ִ� Ÿ��
	/// Type::StaticClass() : Type �� UClass �� ����ϴ�.
	
	// ����� �÷��̾� ��Ʈ�ѷ��� �����մϴ�.
	PlayerControllerClass = AGamePlayerControllerBase::StaticClass();
}