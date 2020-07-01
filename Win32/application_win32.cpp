#include "application_win32.h"
#include <Windows.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PWSTR pCmdLine, int nCmdShow)
{
	MessageBox(NULL, "Goodbye, cruel world!", "Note", MB_OK);
	return 0;
}

std::unique_ptr<application> application::create(int argc, char* argv[])
{
	return std::make_unique<applicationWin32>(argc, argv);
}

applicationWin32::applicationWin32(int argc, char* argv[])
{
	
}

applicationWin32::~applicationWin32()
{

}

void applicationWin32::run()
{
	
}

void applicationWin32::update()
{

}