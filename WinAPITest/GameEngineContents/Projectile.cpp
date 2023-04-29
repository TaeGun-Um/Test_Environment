#include "Projectile.h"

#include <GameEngineCore/GameEngineRender.h>
#include <cmath>
#include "ContentsEnum.h"


Projectile::Projectile() 
{
}

Projectile::~Projectile() 
{
}

void Projectile::Start()
{
	AnimationRender = CreateRender(RenderOrder::Player);
	AnimationRender->SetScale({ 400.0f, 400.0f });
	AnimationRender->CreateAnimation({ .AnimationName = "Idle",  .ImageName = "Soldier_Boom_L.bmp", .Start = 0, .End = 11, .InterTime = 0.1f });
	AnimationRender->ChangeAnimation("Idle");
}

void Projectile::Update(float _DeltaTime)
{
	if (Count == 1)
	{
		Count = 0;
		Quadraticfunction(_DeltaTime);
	}

	ProjectileCal(_DeltaTime);
}

void Projectile::ProjectileCal(float _DeltaTime)
{
	Timer += _DeltaTime * 0.5f;

	float4 NowPos = float4::LerpClamp(StartPosX, EndPosX, Timer);

	float YPos = a * ((NowPos.x - VertexX) * (NowPos.x - VertexX)) + q;

	SetPos({ NowPos.x, YPos});
}

void Projectile::Quadraticfunction(float _DeltaTime)
{
	// ���� ratio(������ x), y ������(StartPos���� ��)

	float p = VertexX;            // x ������
	q = 100.0f;                   // y ������
	a = 0.0f;                     // ��
	
	float Shoot_x = ShootPos.x;   // ���� x
	float Shoot_y = ShootPos.y;   // ���� y

	float Target_y = TargetPos.y; // ���� y
	float Target_x = TargetPos.x; // ���� x

	a = (Shoot_y - q) / ((Shoot_x - VertexX) * (Shoot_x - VertexX));

	XPos = GetPos().x;
	StartPosX.x = Shoot_x;
	EndPosX.x = Target_x;
}