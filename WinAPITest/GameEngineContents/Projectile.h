#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Projectile : public GameEngineActor
{
public:
	// constrcuter destructer
	Projectile();
	~Projectile();

	// delete Function
	Projectile(const Projectile& _Other) = delete;
	Projectile(Projectile&& _Other) noexcept = delete;
	Projectile& operator=(const Projectile& _Other) = delete;
	Projectile& operator=(Projectile&& _Other) noexcept = delete;

	void SetShootPos(float4 _Pos)
	{
		ShootPos = _Pos;
	}

	void SetTargetPos(float4 _Pos)
	{
		TargetPos = _Pos;
	}

	void SetVertexX(float _Pos)
	{
		VertexX = _Pos;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) {}

private:
	class GameEngineRender* AnimationRender = nullptr;

	float4 ShootPos = float4::Zero;
	float4 TargetPos = float4::Zero;
	float VertexX = 0.0f;

	int Count = 1;
	float a = 0.0f;
	float q = 0.0f;

	void Quadraticfunction(float _DeltaTime);
	void ProjectileCal(float _DeltaTime);
};

