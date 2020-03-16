#include "..//TesseractFramework/TesseractFrameworkRendererD3D9.h"

#pragma comment(lib,"..//Bin//Debug//TesseractFramework_d.lib")

using namespace TesseractFramework;
LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
HWND CreateRenderWindow(unsigned int width, unsigned int height);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	TesseractFrameworkRenderer* renderer = new TesseractFrameworkRendererD3D9();
	renderer->initializeRenderer();

	HWND window = CreateRenderWindow(800, 600);
	if (window)
	{
		ShowWindow(window, SW_SHOW);
		UpdateWindow(window);
	}
	RendererProperties renProperties = {};
	renProperties.winHandle = window;
	renProperties.backbufferCount = 2;
	renProperties.backbufferWinWidth = 800;
	renProperties.backbufferWinHeight = 600;
	renProperties.fullScreen = false;
	renProperties.vSync.bVerticalSync = false;
	renProperties.stencil = false;
	renProperties.multiSamples.multiSamples = 0;
	renProperties.multiSamples.multiSamplesQuality = 0;
	//renderer->configureRenderer(renProperties);
	renderer->configureRenderer(window, 1, 800, 600, false);

	
	MSG msg = {};
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			if (msg.message == WM_QUIT)
				break;
		}
		renderer->setViewport(0, 0, 300, 300, 0.0f, 1.0f);
		renderer->clear(1.0f, 0.5f, 0.0f, 1.0f);
		renderer->begin();
		renderer->end();
		renderer->setViewport(300, 0, 300, 300, 0.0f, 1.0f);
		renderer->clear(1.0f, 1.0f, 0.0f, 0.0f);
		renderer->begin();
		renderer->end();
		renderer->present();
	}
	delete renderer;
	renderer = 0;
	return 0;
}

HWND CreateRenderWindow(unsigned int width, unsigned int height)
{
	WNDCLASSEX winClassEx;
	ZeroMemory(&winClassEx, sizeof(WNDCLASSEX));

	winClassEx.cbSize = sizeof(WNDCLASSEX);

	winClassEx.style = CS_HREDRAW | CS_VREDRAW;
	winClassEx.lpfnWndProc = WinProc;
	winClassEx.hInstance = GetModuleHandle(NULL);
	winClassEx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	winClassEx.hCursor = LoadCursor(NULL, IDC_ARROW);
	winClassEx.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	winClassEx.lpszClassName = "Tesseractframework";
	winClassEx.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	if (!RegisterClassEx(&winClassEx))
	{
		return NULL;
	}
	return CreateWindowEx(
		WS_EX_OVERLAPPEDWINDOW,
		"Tesseractframework",
		"Tesseract Framework",
		WS_OVERLAPPEDWINDOW, 0, 0,
		width,
		height,
		NULL,
		NULL,
		GetModuleHandle(NULL), NULL);
}

LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_QUIT:
		PostQuitMessage(0);
		break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
		{
			PostQuitMessage(0);
		}
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}