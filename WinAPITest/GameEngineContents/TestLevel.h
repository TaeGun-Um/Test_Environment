#pragma once

#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineResources.h>

// Ό³Έν :
class TestLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	TestLevel();
	~TestLevel();

	// delete Function
	TestLevel(const TestLevel& _Other) = delete;
	TestLevel(TestLevel&& _Other) noexcept = delete;
	TestLevel& operator=(const TestLevel& _Other) = delete;
	TestLevel& operator=(TestLevel&& _Other) noexcept = delete;

protected:
	void Loading();
	void Update(float _DeltaTime);

	void LevelChangeStart(GameEngineLevel* _PrevLevel) override {}
	void LevelChangeEnd(GameEngineLevel* _PrevLevel) override {}

private:
	//GameEngineSoundPlayer BGMPlayer;

	int SoundCount = 1;

};

