
#include "stdafx.h"
#include "GuitarTabStudio.h"
#include "Application.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	Application application(hInstance, lpCmdLine);
	if (application.initialize()) {
		return application.run();
	}
}


