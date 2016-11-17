#ifndef _SYSTEMCLASS_H_
#define _SYSTEMCLASS_H_
// Pre-processing directives to speed up the build proccess
// it reduces the size of Win32 header files by excluding some of the less used APIs
#define WIN32_LEAN_AND_MEAN
// Includes
#include <Windows.h> // use wind32 functions
// My Class includes
#include "inputclass.h"
#include "graphicsclass.h"

class SystemClass
{
public:
	SystemClass();
	SystemClass(const SystemClass&); // Copy constructor
	~SystemClass();

	bool Initialize();
	void Shutdown();
	void Run();

	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

private:
	bool Frame();
	void InitializeWindows(int&, int&);
	void ShutdownWindows();

private:
	LPCWSTR m_applicationName;
	HINSTANCE m_hinstance;
	HWND m_hwnd;

	InputClass* m_Input;
	GraphicsClass* m_Graphics;
};

// Function Prototypes
static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Globals
static SystemClass* ApplicationHandle = 0;


#endif