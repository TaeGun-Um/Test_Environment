#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineString.h>
#include <GameEngineBase/GameEnginePath.h>
#include "GameEngineResources.h"

GameEngineResources GameEngineResources::Inst;

GameEngineResources::GameEngineResources()
{
}

GameEngineResources::~GameEngineResources()
{
}

// 이미지와 사운드 동적할당 해제
void GameEngineResources::Release()
{
	for (std::pair<std::string, GameEngineImage*> Pair : AllImage)
	{
		if (nullptr == Pair.second)
		{
			continue;
		}
		delete Pair.second;
	}
	AllImage.clear();

}

////////////////////////////////////////////// Image //////////////////////////////////////////////

// 경로와 파일명을 문자열로 변환 후 아래 함수 수행
GameEngineImage* GameEngineResources::ImageLoad(const GameEnginePath& _Path)
{
	return ImageLoad(_Path.GetPathToString().c_str(), _Path.GetFileName().c_str());
}

// 결정한 이미지에 대한 동적할당 실시 (GameEngineImage 콜)
GameEngineImage* GameEngineResources::ImageLoad(const std::string_view& _Path, const std::string_view& _Name)
{
	std::string UpperName = GameEngineString::ToUpper(_Name);

	if (AllImage.end() != AllImage.find(UpperName))
	{
		MsgAssert("이미 로드한 이미지를 또 로드하려고 했습니다." + UpperName);
		return nullptr;
	}

	GameEngineImage* NewImage = new GameEngineImage();
	NewImage->ImageLoad(_Path);
	AllImage.insert(std::make_pair(UpperName, NewImage));
	return NewImage;
}

// AllImage map에 저장한 이미지 파일 탐색
GameEngineImage* GameEngineResources::ImageFind(const std::string_view& _Name)
{
	std::string UpperName = GameEngineString::ToUpper(_Name);

	std::map<std::string, GameEngineImage*>::iterator FindIter = AllImage.find(UpperName);

	if (AllImage.end() == FindIter)
	{
		MsgAssert("로드하지 않은 이미지를 사용하려고 했습니다" + UpperName);
		return nullptr;
	}

	return FindIter->second;
}

