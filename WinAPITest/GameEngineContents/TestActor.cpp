#include "TestActor.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnum.h"

TestActor::TestActor() 
{
}

TestActor::~TestActor() 
{
}

void TestActor::Start()
{
	float4 Size = GameEngineWindow::GetScreenSize();
	float4 Size_half = GameEngineWindow::GetScreenSize().half();

	AnimationRender = CreateRender(RenderOrder::Player);
	AnimationRender->SetPosition(Size_half);
	AnimationRender->SetScale({ 400, 400 });
	AnimationRender->CreateAnimation({ .AnimationName = "Idle",  .ImageName = "Sky.bmp", .Start = 0, .End = 5, .InterTime = 0.1f });
	AnimationRender->ChangeAnimation("Idle");
}

void TestActor::Update(float _DeltaTime)
{

}

void TestActor::Render(float _DeltaTime)
{

}