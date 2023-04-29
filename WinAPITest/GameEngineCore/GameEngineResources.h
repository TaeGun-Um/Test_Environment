#pragma once

#include <map>
#include <string>

#include <GameEnginePlatform/GameEngineImage.h>
#include <GameEnginePlatform/GameEngineSound.h>



class GameEnginePath;
class GameEngineImage;
class GameEngineSound;

// ���� : �̱��� Ŭ������ ��� ����, �̹���(���ҽ�)�� map�� ���ҽ� ������ �� �Ŵ�����Ʈ�ϴ� Ŭ����
class GameEngineResources
{
public:
	GameEngineResources(const GameEngineResources& _Other) = delete;
	GameEngineResources(GameEngineResources&& _Other) noexcept = delete;
	GameEngineResources& operator=(const GameEngineResources& _Other) = delete;
	GameEngineResources& operator=(GameEngineResources&& _Other) noexcept = delete;

	// �̱���
	static GameEngineResources& GetInst()
	{
		return Inst;
	}

	// ��ο� ���ϸ��� ���ڿ��� ��ȯ �� �Ʒ� �Լ� ����
	GameEngineImage* ImageLoad(const GameEnginePath& _Path);

	// ������ �̹����� ���� �����Ҵ� �ǽ� (GameEngineImage ��)
	GameEngineImage* ImageLoad(const std::string_view& _Path, const std::string_view& _Name);
	
	// AllImage map�� ������ ���� Ž��
	GameEngineImage* ImageFind(const std::string_view& _Name);

	// �̹��� �����Ҵ� ����
	void Release();



protected:

private:
	GameEngineResources();
	~GameEngineResources();

	static GameEngineResources Inst;
	
	std::map<std::string, GameEngineImage*> AllImage; // ��� �̹���
	std::map<std::string, GameEngineSound*> AllSound; // ��� ����

};

