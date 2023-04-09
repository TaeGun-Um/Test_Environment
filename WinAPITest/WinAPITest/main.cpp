#include <Windows.h>
#include <GameEngineContents/ContentsCore.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	ContentsCore::GetInst().CoreStart(hInstance);
	return 1;
}