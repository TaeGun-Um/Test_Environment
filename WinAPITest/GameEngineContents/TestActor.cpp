#include "TestActor.h"
#include <iostream>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineBase/GameEngineMath.h>
#include <math.h>

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

	MovePos.x = 400.0f;
	MovePos.y = 300.0f;
	Direction.x = 10;
	Direction.y = 10;

	NewPos = GetPos();
}

void TestActor::Update(float _DeltaTime)
{
	//WaggleDance(_DeltaTime);
	//MoveAirplane(_DeltaTime);
	//Rotation(_DeltaTime);
	WaggleDance2(_DeltaTime);
}

void TestActor::Render(float _DeltaTime)
{

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
	// ����� ��ġ ����
	MovePos.x += Direction.x;
	MovePos.y += Direction.y;

	// ����� �̵� ���� ����
	if (MovePos.x < 0.f || MovePos.x > 800.0f) // x�� ��輱�� ������ ���
	{
		Direction.x = -Direction.x; // x�� ���� ����
	}
	else if (MovePos.y < 0.f || MovePos.y > 600.0f) // y�� ��輱�� ������ ���
	{
		Direction.y = -Direction.y; // y�� ���� ����
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

void TestActor::WaggleDance2(float _DeltaTime)
{
	float Time = GetLiveTime();

	float4 Pos = float4::Zero;

	Pos.x = sinf(Time * 1.0f) * 100.0f;
	Pos.y = cosf(Time) * 100.0f;

	SetPos(Pos);
}

void TestActor::GPTRotation()
{
	const float PI = 3.14159265358979323846f;
	const float amplitude = 10.0f; // ����
	const float frequency = 0.1f; // ���ļ�
	float time = 0.0f;

	int Count = 0;

	while (Count != 100)
	{
		// sin �Լ��� ����Ͽ� y��ǥ�� ���
		float y = amplitude * sin(frequency * time * 2.0f * PI);

		// ȭ�鿡 ���
		std::cout << "y = " << y << std::endl;

		// �ð� ����
		time += 0.1f;
		++Count;
	}
}