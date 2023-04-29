#include "Player.h"

#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"

Player* Player::MainPlayer = nullptr;

Player::Player() 
{
}

Player::~Player() 
{
}

void Player::Start()
{
	MainPlayer = this;

	AnimationRender = CreateRender(RenderOrder::Player);
	//AnimationRender->SetPosition({ 100.0f, 600.0f });
	AnimationRender->SetScale({ 400.0f, 400.0f });
	AnimationRender->CreateAnimation({ .AnimationName = "Idle",  .ImageName = "Wrench.bmp", .Start = 14, .End = 21, .InterTime = 0.1f });
	AnimationRender->ChangeAnimation("Idle");

}

void Player::Update(float _DeltaTime)
{
	Move(_DeltaTime);
}


void Player::Move(float _DeltaTime)
{
	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		SetMove(float4::Left * 300.0f * _DeltaTime);
	}
	else if (true == GameEngineInput::IsPress("RightMove"))
	{
		SetMove(float4::Right * 300.0f * _DeltaTime);
	}
	else if (true == GameEngineInput::IsPress("UpMove"))
	{
		SetMove(float4::Up * 300.0f * _DeltaTime);
	}
	else if (true == GameEngineInput::IsPress("DownMove"))
	{
		SetMove(float4::Down * 300.0f * _DeltaTime);
	}
}

