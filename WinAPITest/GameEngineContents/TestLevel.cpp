#include "TestLevel.h"

#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include "TestActor.h"

TestLevel::TestLevel() 
{
}

TestLevel::~TestLevel() 
{
}

void TestLevel::Loading()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("Resources");
	Dir.Move("Resources");

	GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Title(recorder).mp3"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Sky.bmp"))->Cut(5, 9);

	if (false == GameEngineInput::IsKey("UpMove"))
	{
		GameEngineInput::CreateKey("UpMove", VK_UP);
		GameEngineInput::CreateKey("DownMove", VK_DOWN);
		GameEngineInput::CreateKey("LeftMove", VK_LEFT);
		GameEngineInput::CreateKey("RightMove", VK_RIGHT);
		GameEngineInput::CreateKey("Action", 'Z');
	}

	CreateActor<TestActor>();
}

void TestLevel::Update(float _DeltaTime)
{
	if (SoundCount == 1)
	{
		SoundCount = 0;
		BGMPlayer = GameEngineResources::GetInst().SoundPlayToControl("Title(recorder).mp3");
		BGMPlayer.Volume(0.3f);
		BGMPlayer.LoopCount(100);
	}
}