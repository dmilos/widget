#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <thread>

#include "./win32.hpp"
#include "../../canvas/native.hpp"

widget::event::generator::win32::win32()
 {
  m_run = false;
  m_hWnd = NULL;
 }

widget::event::generator::win32::~win32()
 {
  stop();
 }

void widget::event::generator::win32::element( element_ptr_type element_param )
 {
  element_ptr() = element_param;
  if( NULL != m_hWnd )
   {
  SetWindowLongPtr(m_hWnd, GWLP_USERDATA, (LONG_PTR)element_ptr());
   }
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
  if (false == m_run)
   {
    return;
   }

  if( true == m_thread.joinable() )
   {
    if (NULL != m_hWnd)
     {
      PostMessage(m_hWnd, WM_CLOSE, 0, 0);
     }

    m_thread.join();
   }

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

  SetWindowLongPtr( m_hWnd, GWLP_USERDATA, (LONG_PTR)element_ptr() );

  ShowWindow(m_hWnd, SW_SHOW);
  UpdateWindow(m_hWnd);

  MSG msg;
  while( GetMessage( &msg, NULL, 0, 0 ) )
   {
    TranslateMessage( &msg );
    DispatchMessage( &msg );
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
    "",
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT,
    500, 500,
    NULL,
    NULL,
    GetModuleHandle(0),
    NULL
  );

  return hWnd;
 }


LRESULT CALLBACK widget::event::generator::win32::WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
 {
  PAINTSTRUCT ps;
  HDC hdc;
  TCHAR greeting[] = _T("Hello, World!");

  ::widget::element::pure *element = (::widget::element::pure *) GetWindowLongPtr( hWnd, GWLP_USERDATA );
  ::widget::canvas::native const*canvas = nullptr;
  if( nullptr != element )
   {
    canvas = static_cast<::widget::canvas::native const*>(&(element->canvas()));
   }

  switch( message )
   {
    case WM_CLOSE:
      DestroyWindow(hWnd);
     break;
    case WM_PAINT:
     {
      if (nullptr == canvas)
       {
        break;
       }

      hdc = BeginPaint(hWnd, &ps);

      BitBlt( hdc, canvas->offset()[0], canvas->offset()[1], canvas->size()[0], canvas->size()[1], canvas->m_dc, 0, 0, SRCCOPY);

      EndPaint(hWnd, &ps);

     }break;
    case WM_DESTROY:
      PostQuitMessage(0);
     break;
    default:
      return DefWindowProc(hWnd, message, wParam, lParam);
     break;
  }

  return 0;
 }
