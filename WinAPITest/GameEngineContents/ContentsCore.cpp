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

	// ------------------------------- ���� ���� -------------------------------
	ChangeLevel("TestLevel");
}

void ContentsCore::Update()
{
}

void ContentsCore::End()
{
}