#pragma once
#include <GameEngineCore/GameEngineCore.h>

// ¼³¸í : ½Ì±ÛÅæ
class ContentsCore : public GameEngineCore
{
public:
	// delete Function
	ContentsCore(const ContentsCore& _Other) = delete;
	ContentsCore(ContentsCore&& _Other) noexcept = delete;
	ContentsCore& operator=(const ContentsCore& _Other) = delete;
	ContentsCore& operator=(ContentsCore&& _Other) noexcept = delete;

	// ½Ì±ÛÅæ
	static ContentsCore& GetInst()
	{
		return Core;
	}

protected:
	// GameEngineCore ¼ø¼ö °¡»óÇÔ¼ö ovrride
	void Start() override;
	void Update() override;
	void End() override;

private:
	ContentsCore();
	~ContentsCore();

	static ContentsCore Core;

};