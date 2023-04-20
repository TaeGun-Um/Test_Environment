#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class TestActor : public GameEngineActor
{
public:
	// constrcuter destructer
	TestActor();
	~TestActor();

	// delete Function
	TestActor(const TestActor& _Other) = delete;
	TestActor(TestActor&& _Other) noexcept = delete;
	TestActor& operator=(const TestActor& _Other) = delete;
	TestActor& operator=(TestActor&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) {}

private:
	class GameEngineRender* AnimationRender = nullptr;
	class GameEngineCollision* BodyCollision = nullptr;

	float Progress = 0.0f;
	float RotationTime = 0.0f;
	float Angle = 0.0f;
	float AngleCount = 1.0f;

	bool RotP = true;
	bool Waggle = true;
	bool IsStart = false;
	bool IsWaveStart = false;

	float4 MovePos = float4::Zero;
	float4 Direction = float4::Zero;
	float4 NewPos = float4::Zero;
	float4 Pivot = float4::Zero;

	void WaggleDance(float _DeltaTime);
	void WaggleDance2(float _DeltaTime);
	void WaggleDance3(float _DeltaTime);
	void MoveAirplane(float _DeltaTime);
	void Rotation(float _DeltaTime);
	void GPTRotation();

	void WaveMove(float _DeltaTime);

	void CreateBoom();

};

