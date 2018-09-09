#include "stdafx.h"

RenderWindow* RenderWindow::Current = nullptr;

LRESULT CALLBACK RenderWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections: 
		switch (wmId)
		{
		case ID_FILE_EXIT:
			DestroyWindow(hWnd);
			break;

		case ID_FILE_SAVEIMAGE:
			
			RenderWindow::Current->SaveRenderedImage();

			break;

		case ID_FILE_OPENSCENE:

			RenderWindow::Current->LoadScene();

			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		RenderWindow::Current->OnPaint(hdc);


		EndPaint(hWnd, &ps);
		break;

	case WM_TIMER:

		switch (wParam)
		{
		case IDT_TIMER1:
			RenderWindow::Current->EnableRedraw();
		}

		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

RenderWindow::RenderWindow(const int width, const int height)
{
	_width = width;
	_height =  height;

	bitmap = nullptr;
	redrawEnabled = true;
	redrawRequested = false;

	maxRedrawsPerSecond = 1;
}

void RenderWindow::SetPixel(const int x, const int y, const Gdiplus::Color colour)
{
	renderLock.lock();
	bitmap->SetPixel(x, _height - y - 1, colour);
	renderLock.unlock();
}

void RenderWindow::OnPaint(HDC hWnd)
{
	renderLock.lock();

	Gdiplus::Graphics g(hWnd);

	g.DrawImage(bitmap, 0, 0);

	renderLock.unlock();

}

void RenderWindow::EnableRedraw()
{
	redrawEnabled = true;
	
	if (redrawRequested)
	{
		Redraw();
	}
}

void RenderWindow::Redraw()
{
	if (redrawEnabled)
	{
		redrawEnabled = false;
		InvalidateRect(windowHandle, NULL, TRUE);
		redrawRequested = false;
	}
	else
	{
		redrawRequested = true;
	}
}

int RenderWindow::OpenWindow()
{
	if (RenderWindow::Current)
	{
		throw "A render window has already been opened.";
	}
	else
	{
		RenderWindow::Current = this;
	}

	HINSTANCE hInstance = WinMainParameters::GetHInstance();
	HINSTANCE hPrevInstance = WinMainParameters::GetHPrevInstance();
	LPWSTR lpCmdLine = WinMainParameters::GetLPCmdLine();
	int nCmdShow = WinMainParameters::GetNCmdShow();

	// The title bar text
	TCHAR szTitle[MAX_LOADSTRING];
	// The main window class name
	TCHAR szWindowClass[MAX_LOADSTRING];

	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(nCmdShow);

	MSG msg;
	HACCEL hAccelTable;

	// Initialize Global Strings

	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_LAUNCHWIN32WINDOWFROMCONSOLE, szWindowClass, MAX_LOADSTRING);

	Gdiplus::GdiplusStartupInput gdiplusStartupInput;

	Gdiplus::GdiplusStartup(&gdiPlusToken, &gdiplusStartupInput, NULL);
	bitmap = new Gdiplus::Bitmap(_width, _height);

	Gdiplus::PixelFormat foo;


	ATOM wndClass = MyRegisterClass(hInstance);

	if (!InitInstance(hInstance, nCmdShow))
	{
		return -1;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAUNCHWIN32WINDOWFROMCONSOLE));

	// Start a timer so we can limit redraws.
	StartRedrawTimer(windowHandle);

	isWindowRunning = true;

	// Initialize COM

	HRESULT result = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

	if (!SUCCEEDED(result))
	{
		return -1;
	}

	// Main message loop.
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (msg.message == WM_QUIT)
		{
			break;
		}

		std::this_thread::yield();
	}

	isWindowRunning = false;
	RenderWindow::Current = nullptr;

	if (bitmap)
	{
		delete bitmap;
		bitmap = nullptr;
	}

	Gdiplus::GdiplusShutdown(gdiPlusToken);

	KillTimer(windowHandle, IDT_TIMER1);

	// Shut down COM
	CoUninitialize();

	return (int)msg.wParam;
}

BOOL RenderWindow::InitInstance(HINSTANCE hInstance, int nCmdShow)
{

	// Get the window size for our desired client area size.
	RECT clientSize;

	SetRect(&clientSize, 0, 0, _width, _height);
	//TODO: When I add a menu, I have to remember to update this function to include that in the client area sizing.
	BOOL result = AdjustWindowRectEx(&clientSize, WS_OVERLAPPEDWINDOW, FALSE, 0);

	if (!result)
	{
		DWORD errorCode = GetLastError();

		std::cerr << "An error with code " << errorCode << " occured calling AdjustWindowRectEx." << std::endl;
		throw std::exception("An error occured calling AdjustWindowRectEx.");
	}

	hInst = hInstance;
	HMENU menuHandle = LoadRenderWindowMenu();

	windowHandle = CreateWindowEx(
		NULL,
		L"PenthesileaRenderWindow",
		L"Penthesilea",
		WS_OVERLAPPED | WS_MINIMIZEBOX | WS_SYSMENU | WS_CAPTION,
		300, 300,
		clientSize.right - clientSize.left, clientSize.bottom - clientSize.top,
		NULL,
		menuHandle,
		hInstance,
		NULL
		);

	if (!windowHandle)
	{
		return FALSE;
	}

	ShowWindow(windowHandle, nCmdShow);
	UpdateWindow(windowHandle);

	return TRUE;
}

ATOM RenderWindow::MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX winClass;
	ZeroMemory(&winClass, sizeof(WNDCLASSEX));


	winClass.cbSize = sizeof(WNDCLASSEX);
	winClass.style = CS_HREDRAW | CS_VREDRAW;
	winClass.lpfnWndProc = RenderWndProc;
	winClass.hInstance = hInstance;
	winClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winClass.hbrBackground = (HBRUSH)(COLOR_WINDOW);
	//winClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	winClass.lpszClassName = L"PenthesileaRenderWindow";

	/*
	winClass.cbClsExtra = 0;
	winClass.cbWndExtra = 0;
	winClass.hIconSm = NULL;
	*/

	ATOM result = RegisterClassEx(&winClass);

	if (result <= 0)
	{
		DWORD errorCode = GetLastError();
		std::cerr << "RegisterClassEx failed with error code: " << errorCode << ".\r\n";
			
	}

	return result;
}

void RenderWindow::StartRedrawTimer(HWND windowHandle)
{
	UINT timePerFrame = (UINT)(1000.0 / maxRedrawsPerSecond);

	SetTimer(windowHandle, IDT_TIMER1, timePerFrame, NULL);
}

HMENU RenderWindow::LoadRenderWindowMenu()
{
	HMENU handle = LoadMenu(hInst, MAKEINTRESOURCE(IDR_MENU1));

	if (handle == NULL)
	{
		DWORD lastErrorCode = GetLastError();

		std::cout << "Unable to load menu resource. Error code: " << lastErrorCode << std::endl;
	}

	return handle;
}

void RenderWindow::LoadScene()
{
	std::string inputPath;

	if (GetOpenScenePath(inputPath))
	{

	}
	else
	{
		std::cerr << "Unable to open scene." << std::endl;
	}
}

void RenderWindow::SaveRenderedImage()
{
	std::string outputPath;

	if (GetSaveImagePath(outputPath))
	{
		std::vector<unsigned char> pixelBytes = GetPixelBytes();

		// Default encoding is RGBA
		unsigned int error = lodepng::encode(outputPath, pixelBytes, _width, _height);

		if (error > 0)
		{
			std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
		}
		else
		{
			std::cout << "Save complete." << std::endl;
		}
	}
	else
	{
		std::cerr << "Unable to save image." << std::endl;
	}
}

std::vector<unsigned char> RenderWindow::GetPixelBytes()
{
	Gdiplus::Rect imageRect(0, 0, _width, _height);
	Gdiplus::BitmapData* bitmapData = new Gdiplus::BitmapData();

	bitmap->LockBits(&imageRect, Gdiplus::ImageLockModeRead, PixelFormat32bppARGB, bitmapData);

	std::vector<unsigned char> imageBytes;

	unsigned char* pixels = (unsigned char*)bitmapData->Scan0;

	int byteCount = _width * _height * 4;

	for (int i = 0; i < byteCount; i += 4)
	{
		//bgra

		unsigned char b = pixels[i];
		unsigned char g = pixels[i+1];
		unsigned char r = pixels[i+2];
		unsigned char a = pixels[i+3];

		imageBytes.push_back(r);
		imageBytes.push_back(g);
		imageBytes.push_back(b);
		imageBytes.push_back(a);

	}

	//for (int y = 0; y < _height; y++)
	//{
	//	for (int x = 0; x < _width; x++)
	//	{
	//		unsigned char pixel = pixels[y * bitmapData->Stride / 4 + x];

	//		imageBytes.push_back(pixel & 0x00FF0000); // R
	//		imageBytes.push_back(pixel & 0x0000FF00); // G
	//		imageBytes.push_back(pixel & 0x000000FF); // B
	//		imageBytes.push_back(pixel & 0xFF000000); // A
	//	}
	//}

	bitmap->UnlockBits(bitmapData);

	delete bitmapData;

	return imageBytes;
}

bool RenderWindow::GetOpenScenePath(std::string& inputPath) const
{
	return false;
}

bool RenderWindow::GetSaveImagePath(std::string& outputPath) const
{
	bool proceedWithSave = false;

	HRESULT result;
		IFileSaveDialog* sfd = nullptr;
		result = CoCreateInstance(CLSID_FileSaveDialog,
			nullptr,
			CLSCTX_ALL,
			IID_IFileSaveDialog,
			reinterpret_cast<void**>(&sfd));

	if (SUCCEEDED(result))
	{
		COMDLG_FILTERSPEC saveTypesArray[] =
		{
			{ L"PNG", L"*.png" },
		};

		sfd->SetFileTypes(ARRAYSIZE(saveTypesArray), saveTypesArray);

		result = sfd->Show(windowHandle);

		if (SUCCEEDED(result))
		{
			IShellItem* sItem;
			result = sfd->GetResult(&sItem);

			if (SUCCEEDED(result))
			{
				PWSTR filePath;
				result = sItem->GetDisplayName(SIGDN_FILESYSPATH, &filePath);

				if (SUCCEEDED(result))
				{
					std::wstringstream stream;

					stream << filePath;

					outputPath = std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>().to_bytes(stream.str());

					//outputPath = std::wstring_convert <std::string>( stream.str());
					proceedWithSave = true;

					CoTaskMemFree(filePath);
				}

				sItem->Release();
			}

		}

		sfd->Release();

	}

	return proceedWithSave;
}

RenderWindow::~RenderWindow()
{
	
}