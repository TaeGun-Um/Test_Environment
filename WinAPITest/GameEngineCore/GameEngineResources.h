#pragma once

#include <map>
#include <string>

#include <GameEnginePlatform/GameEngineImage.h>
#include <GameEnginePlatform/GameEngineSound.h>



class GameEnginePath;
class GameEngineImage;
class GameEngineSound;

// 설명 : 싱글톤 클래스로 모든 사운드, 이미지(리소스)를 map에 리소스 저장한 뒤 매니지먼트하는 클래스
class GameEngineResources
{
public:
	GameEngineResources(const GameEngineResources& _Other) = delete;
	GameEngineResources(GameEngineResources&& _Other) noexcept = delete;
	GameEngineResources& operator=(const GameEngineResources& _Other) = delete;
	GameEngineResources& operator=(GameEngineResources&& _Other) noexcept = delete;

	// 싱글톤
	static GameEngineResources& GetInst()
	{
		return Inst;
	}

	// 경로와 파일명을 문자열로 변환 후 아래 함수 수행
	GameEngineImage* ImageLoad(const GameEnginePath& _Path);

	// 결정한 이미지에 대한 동적할당 실시 (GameEngineImage 콜)
	GameEngineImage* ImageLoad(const std::string_view& _Path, const std::string_view& _Name);
	
	// AllImage map에 저장한 파일 탐색
	GameEngineImage* ImageFind(const std::string_view& _Name);

	// 이미지 동적할당 해제
	void Release();



protected:

private:
	GameEngineResources();
	~GameEngineResources();

	static GameEngineResources Inst;
	
	std::map<std::string, GameEngineImage*> AllImage; // 모든 이미지
	std::map<std::string, GameEngineSound*> AllSound; // 모든 사운드

};

