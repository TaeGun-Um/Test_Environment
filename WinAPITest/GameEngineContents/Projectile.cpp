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
	SetMove(float4::Left * 500.0f * _DeltaTime);

	float YPos = a * ((GetPos().x - VertexX) * (GetPos().x - VertexX)) + q;

	SetPos({GetPos().x, YPos });
}

void Projectile::Quadraticfunction(float _DeltaTime)
{
	// ���� ratio(������ x), y ������(StartPos���� ��)

	float p = VertexX;            // x ������
	q = 100.0f;                   // y ������
	a = 0.0f;                     // ��
	
	float Shoot_x = ShootPos.x;   // ���� x
	float Shoot_y = ShootPos.y;   // ���� y

	float Target_y = TargetPos.y; // ���� x
	float Target_x = TargetPos.x; // ���� y

	a = (Shoot_y - q) / ((Shoot_x - VertexX) * (Shoot_x - VertexX));

}