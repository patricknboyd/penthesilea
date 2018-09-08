#pragma once
#include "stdafx.h"

#define MAX_LOADSTRING 100
#define IDT_TIMER1 1001

class RGBColour;

class RenderWindow
{
public:

	static RenderWindow* Current;

	RenderWindow(const int width, const int height);
	RenderWindow(const RenderWindow& rw) = delete;
	~RenderWindow();

	RenderWindow& operator= (const RenderWindow&) = delete;

	int OpenWindow();

	void OnPaint(HDC hWnd);
	void SetPixel(const int x, const int y, const Gdiplus::Color colour);
	void Redraw();

	void EnableRedraw();
	void SaveRenderedImage();

	bool IsWindowRunning() const { return isWindowRunning; }

private:

	int _width;
	int _height;
	bool redrawEnabled;
	bool redrawRequested;
	bool isWindowRunning;

	Float maxRedrawsPerSecond;

	HWND windowHandle;

	// Save the instance handle and create the window.
	BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);
	// Registers the window class.
	ATOM MyRegisterClass(HINSTANCE hInstance);

	void StartRedrawTimer(HWND windowHandle);

	HMENU LoadRenderWindowMenu();

	bool GetSaveImagePath(std::string& outputPath) const;
	std::vector<unsigned char> GetPixelBytes();

	// The current instance
	HINSTANCE hInst;
	// The title bar text
	TCHAR szTitle[MAX_LOADSTRING];
	// The main window class name
	TCHAR szWindowClass[MAX_LOADSTRING];
	ULONG_PTR gdiPlusToken;

	Gdiplus::Bitmap* bitmap;

	std::vector<std::vector<Gdiplus::Color>> pixels;
	std::mutex renderLock;



};