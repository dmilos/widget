#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <thread>

#include "./win32.hpp"

widget::event::generator::win32::win32()
 {
  m_run = false;
  m_hWnd = NULL;
 }

widget::event::generator::win32::~win32()
 {
	stop();
 }

bool widget::event::generator::win32::run()
 {
  if (true == m_run)
   {
	return true;
   }

  m_run = true;
  m_thread = std::thread( &widget::event::generator::win32::loop, this  );

  return true;
 }
 
void widget::event::generator::win32::stop()
 {
 PostMessage( m_hWnd, WM_CLOSE, 0, 0);

  m_thread.join();
  m_run = false;
 }

void widget::event::generator::win32::loop()
{
	if (false == registerClass())
	{
		return;
	}

	m_hWnd = makeInstance();
	if (NULL == m_hWnd)
	{
		return;
	}
	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);

	MSG msg;
	while ( GetMessage(&msg, NULL, 0, 0) )
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}


bool widget::event::generator::win32::registerClass()
{
	// if( GetClassInfoW

	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = GetModuleHandle(0);
	wcex.hIcon = LoadIcon(GetModuleHandle(0), MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = "{7969DD8A-EB0E-4E5F-9848-692BCA2D76F7}";
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	if (!RegisterClassEx(&wcex))
	{
		return false;
	}

	return true;
}

HWND widget::event::generator::win32::makeInstance()
{
	HWND hWnd = CreateWindow(
		"{7969DD8A-EB0E-4E5F-9848-692BCA2D76F7}",
		"title",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		500, 100,
		NULL,
		NULL,
		GetModuleHandle(0),
		NULL
	);

	return hWnd;
}


LRESULT CALLBACK widget::event::generator::win32::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("Hello, World!");

	switch (message)
	{
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		// Here your application is laid out.
		// For this introduction, we just print out "Hello, World!"
		// in the top left corner.
		TextOut(hdc,
			5, 5,
			greeting, _tcslen(greeting));
		// End application specific layout section.

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}






