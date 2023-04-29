#include "LineX.h"

#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"

LineX::LineX() 
{
}

LineX::~LineX() 
{
}

void LineX::Start()
{
	AnimationRender = CreateRender("Line.Bmp", RenderOrder::Player);
	AnimationRender->SetScale(AnimationRender->GetImage()->GetImageScale());
}
void LineX::Update(float _DeltaTime)
{
	if (2.0f <= GetLiveTime())
	{
		AnimationRender->GetActor()->Death();
	}
}