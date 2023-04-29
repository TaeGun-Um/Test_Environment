#include "TestLevel.h"

#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>

#include "TestActor.h"
#include "Player.h"

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

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Sky.bmp"))->Cut(5, 9);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Wrench.bmp"))->Cut(5, 5);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Soldier_Boom_L.bmp"))->Cut(12, 1);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Line.bmp"));

	if (false == GameEngineInput::IsKey("UpMove"))
	{
		GameEngineInput::CreateKey("UpMove", VK_UP);
		GameEngineInput::CreateKey("DownMove", VK_DOWN);
		GameEngineInput::CreateKey("LeftMove", VK_LEFT);
		GameEngineInput::CreateKey("RightMove", VK_RIGHT);
		GameEngineInput::CreateKey("Action", 'Q');
	}

	float4 Size = GameEngineWindow::GetScreenSize();
	float4 Size_half = GameEngineWindow::GetScreenSize().half();

	CreateActor<TestActor>();
	CreateActor<Player>()->SetPos({ 100.0f, 600.0f });
}

void TestLevel::Update(float _DeltaTime)
{
	//if (SoundCount == 1)
	//{
	//	SoundCount = 0;
	//	BGMPlayer = GameEngineResources::GetInst().SoundPlayToControl("Title(recorder).mp3");
	//	BGMPlayer.Volume(0.3f);
	//	BGMPlayer.LoopCount(100);
	//}
}