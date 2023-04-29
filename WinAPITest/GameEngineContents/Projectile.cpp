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
	// 러프 ratio(꼭짓점 x), y 꼭짓점(StartPos보다 위)

	float p = VertexX;            // x 꼭짓점
	q = 100.0f;                   // y 꼭짓점
	a = 0.0f;                     // 폭
	
	float Shoot_x = ShootPos.x;   // 시작 x
	float Shoot_y = ShootPos.y;   // 시작 y

	float Target_y = TargetPos.y; // 종료 y
	float Target_x = TargetPos.x; // 종료 x

	a = (Shoot_y - q) / ((Shoot_x - VertexX) * (Shoot_x - VertexX));

	XPos = GetPos().x;
	StartPosX.x = Shoot_x;
	EndPosX.x = Target_x;
}