#include "ContentsCore.h"

#include "TestLevel.h"

ContentsCore ContentsCore::Core;

ContentsCore::ContentsCore() 
{
}

ContentsCore::~ContentsCore() 
{
}

void ContentsCore::Start()
{
	CreateLevel<TestLevel>("TestLevel");

	// ------------------------------- 레벨 선택 -------------------------------
	ChangeLevel("TestLevel");
}

void ContentsCore::Update()
{
}

void ContentsCore::End()
{
}