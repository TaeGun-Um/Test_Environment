#include "TestActor.h"
#include <iostream>

#include <GameEngineBase/GameEngineMath.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineBase/GameEngineMath.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <math.h>

#include "Projectile.h"
#include "Player.h"
#include "LineX.h"
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
	AnimationRender->SetPosition(Size_half + float4{350.0f, -50.0f});
	AnimationRender->SetScale({ 400, 400 });
	AnimationRender->CreateAnimation({ .AnimationName = "Idle",  .ImageName = "Sky.bmp", .Start = 0, .End = 5, .InterTime = 0.1f });
	AnimationRender->ChangeAnimation("Idle");

	MovePos.x = 400.0f;
	MovePos.y = 300.0f;
	Direction.x = 10;
	Direction.y = 10;

	// NewPos = GetPos();
	NewPos = AnimationRender->GetPosition();
}

void TestActor::Update(float _DeltaTime)
{
	//WaggleDance(_DeltaTime);
	//MoveAirplane(_DeltaTime);
	//Rotation(_DeltaTime);
	//

	//if (GameEngineInput::IsDown("Action"))
	//{
	//	IsWaveStart = true;
	//}

	//if (IsWaveStart == true)
	//{
	//	WaveMove(_DeltaTime);
	//}
	

	//if (GameEngineInput::IsDown("Action"))
	//{
	//	IsStart = true;
	//}

	//if (Waggle == true && IsStart == true)
	//{
	//	WaggleDance2(_DeltaTime);
	//}

	//if (Waggle == false && IsStart == true)
	//{
	//	WaggleDance3(_DeltaTime);
	//}
	
	if (true == GameEngineInput::IsDown("Action"))
	{
		CreateBoom();
	}
	
}

void TestActor::CreateBoom()
{
	Projectile* NewP = GetLevel()->CreateActor<Projectile>();
	LineX* NewLine = GetLevel()->CreateActor<LineX>();

	float4 Size = GameEngineWindow::GetScreenSize();
	float4 Size_half = GameEngineWindow::GetScreenSize().half();

	float4 PlayerPos = Player::MainPlayer->GetPos();
	float4 TestPos = AnimationRender->GetPosition() + float4{0.0f, -100.0f};

	float XL = float4::Lerp(TestPos, PlayerPos, 0.35f).x;
	float YL = Size_half.y;
	float4 LinePos = float4{ XL, YL };

	NewP->SetPos(TestPos);
	NewP->SetShootPos(TestPos);
	NewP->SetTargetPos(PlayerPos);
	NewP->SetVertexX(XL);

	NewLine->SetPos(LinePos);
}

void TestActor::WaveMove(float _DeltaTime)
{
	Progress += _DeltaTime;

	float Time = Progress * 3.0f;

	float4 Pos = float4::Zero;

	//Posision.x = sinf(Progress * 10.0f);

	//float4 LeftMove = float4::Left * 100.0f * _DeltaTime;

	//SetMove(LeftMove);

	Pos.x -= Time * 50.0f;
	Pos.y = -sinf(Time) * 100.0f;

	SetPos(Pos);
}

void TestActor::WaggleDance2(float _DeltaTime)
{
	Progress += _DeltaTime;

	float Time = Progress * 3.0f;

	float4 Pos = float4::Zero;

	Pos.x = sinf(Time * 1.0f + GameEngineMath::PIE) * 100.0f;
	Pos.y = cosf(Time + GameEngineMath::PIE) * 100.0f;

	if (GameEngineMath::PIE2 <= Time)
	{
		int RandC = GameEngineRandom::MainRandom.RandomInt(1, 3);

		if (RandC == 1)
		{
			Waggle = true;
		}
		else
		{
			Waggle = false;
		}

		Progress = 0.0f;
	}

	SetPos(Pos + float4::Down * 100.0f);
}

void TestActor::WaggleDance3(float _DeltaTime)
{
	Progress += _DeltaTime;

	float Time = -(Progress * 3.0f);

	float4 Pos = float4::Zero;

	Pos.x = sinf(Time * 1.0f) * 100.0f;
	Pos.y = cosf(Time) * 100.0f - 200.0f;

	if (-GameEngineMath::PIE2 >= Time)
	{
		int RandC = GameEngineRandom::MainRandom.RandomInt(1, 3);

		if (RandC == 1)
		{
			Waggle = false;
		}
		else
		{
			Waggle = true;
		}

		Progress = 0.0f;
	}

	SetPos(Pos + float4::Down * 100.0f);
}

void TestActor::WaggleDance(float _DeltaTime)
{
	Progress += _DeltaTime;

	float4 Posision = float4::Zero;

	Posision.x = sinf(Progress * 10.0f);
	Posision.y = cosf(Progress * 10.0f);

	SetMove(Posision);
}

void TestActor::MoveAirplane(float _DeltaTime)
{
	// 비행기 위치 갱신
	MovePos.x += Direction.x;
	MovePos.y += Direction.y;

	// 비행기 이동 방향 변경
	if (MovePos.x < 0.f || MovePos.x > 800.0f) // x축 경계선에 도달한 경우
	{
		Direction.x = -Direction.x; // x축 방향 반전
	}
	else if (MovePos.y < 0.f || MovePos.y > 600.0f) // y축 경계선에 도달한 경우
	{
		Direction.y = -Direction.y; // y축 방향 반전
	}

	SetMove(MovePos * _DeltaTime);
}

void TestActor::Rotation(float _Deltatime)
{
	RotationTime += _Deltatime;

	if (0.001f <= RotationTime && true == RotP)
	{
		Angle += 1.0f;
		RotationTime = 0.0f;
	}

	if (0.001f <= RotationTime && false == RotP)
	{
		Angle -= 1.0f;
		RotationTime = 0.0f;
	}

	float4 Dir = float4::AngleToDirection2DToDeg(Angle);
	SetPos(NewPos + Dir * 100.0f);

	if (360.0f <= Angle && true == RotP)
	{
		Angle = 0;
		RotP = false;
	}

	if (-360.0f >= Angle && false == RotP)
	{
		Angle = 0;
		RotP = true;
	}
}


void TestActor::GPTRotation()
{
	const float PI = 3.14159265358979323846f;
	const float amplitude = 10.0f; // 진폭
	const float frequency = 0.1f; // 주파수
	float time = 0.0f;

	int Count = 0;

	while (Count != 100)
	{
		// sin 함수를 사용하여 y좌표를 계산
		float y = amplitude * sin(frequency * time * 2.0f * PI);

		// 화면에 출력
		std::cout << "y = " << y << std::endl;

		// 시간 증가
		time += 0.1f;
		++Count;
	}
}