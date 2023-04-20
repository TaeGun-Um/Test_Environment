#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class LineX : public GameEngineActor
{
public:
	// constrcuter destructer
	LineX();
	~LineX();

	// delete Function
	LineX(const LineX& _Other) = delete;
	LineX(LineX&& _Other) noexcept = delete;
	LineX& operator=(const LineX& _Other) = delete;
	LineX& operator=(LineX&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) {}

private:
	class GameEngineRender* AnimationRender = nullptr;

};

