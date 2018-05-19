#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <thread>

#include "./win32.hpp"
#include "../../canvas/native.hpp"

widget::event::generator::win32::win32()
 {
  m_hWnd = NULL;
 }

widget::event::generator::win32::~win32()
 {
  stop();
 }

void widget::event::generator::win32::consumer(consumer_ptr_type consumer_param )
 {
  consumer_protected() = consumer_param;
 }

bool widget::event::generator::win32::run()
 {
  if( true == this->active() )
   {
    return true;
   }

  this->active_protected().store( false );

  m_thread = std::thread( &widget::event::generator::win32::loop, this );

  while( false == this->active_protected().load() )
   {
    std::this_thread::yield();
   }

  return true;
 }

void widget::event::generator::win32::stop()
 {
  if( false == this->active() )
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

  this->active_protected().store( false );
 }

void widget::event::generator::win32::loop()
 {
  if (false == registerClass() )
   {
    return;
   }

  this->m_hWnd = makeInstance();
  if( NULL == m_hWnd )
   {
    return;
   }

  SetWindowLongPtr( this->m_hWnd, GWLP_USERDATA, (LONG_PTR)this );
  this->active_protected().store( true );

  ShowWindow( m_hWnd, SW_SHOW );
  UpdateWindow( m_hWnd );

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

  if( !RegisterClassEx(&wcex) )
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
    (LPVOID)this
  );

  return hWnd;
 }


LRESULT CALLBACK widget::event::generator::win32::WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
 {
  ::widget::event::generator::win32 *this_generator = ( widget::event::generator::win32 *) GetWindowLongPtr( hWnd, GWLP_USERDATA );

  switch( message )
   {
    case WM_GETMINMAXINFO:
       break;
    case WM_NCCREATE:
     {
      CREATESTRUCT *cs = (CREATESTRUCT *)( lParam );
      SetWindowLongPtr( hWnd, GWLP_USERDATA, (LONG_PTR)cs->lpCreateParams );
     }break;
    case WM_NCCALCSIZE: break;
    case WM_CREATE: break;

    case WM_CLOSE:
        DestroyWindow(hWnd);
        break;

    case WM_SIZE:
     {
      if( ( nullptr != this_generator ) && ( wParam == SIZE_RESTORED) )
       {
        RECT rect;
        GetWindowRect( hWnd, &rect );
        event_type e( 0, message );
        e.data()[0] = LOBYTE(rect.right  - rect.left );
        e.data()[1] = HIBYTE(rect.right  - rect.left );
        e.data()[2] = LOBYTE(rect.bottom - rect.top  );
        e.data()[3] = HIBYTE(rect.bottom - rect.top  );
        this_generator->consumer_protected()->process( e );
        return DefWindowProc(hWnd, message, wParam, lParam);
       }
     }
     break;
    case WM_PAINT:
     if(false){
       COLORREF clrRed  = RGB(255, 25, 5);
       COLORREF clrAqua = RGB(0, 255, 255);
       COLORREF clrNavy = RGB(0, 0, 128);

       PAINTSTRUCT ps;
       HDC hdc = BeginPaint(hWnd, &ps);

       //BitBlt( hdc, 0, 0, canvas->size()[0], canvas->size()[1], canvas->m_dc, 0, 0, SRCCOPY);

       SetBkColor(hdc, RGB(255, 255, 255));    SetTextColor(hdc, clrRed);    TextOut(hdc, 50, 42, "Johnny Carson", 13);
       SetBkColor(hdc, clrNavy);     SetTextColor(hdc, clrAqua);    TextOut(hdc, 50, 80, "The once king of late-night", 27);
       EndPaint(hWnd, &ps);
     }break;
    case WM_DESTROY:
      PostQuitMessage(0);
     break;
    default:
     break;
  }

  if( nullptr != this_generator )
   {
    if( true == this_generator->consumer_protected()->process( event_type( 0, message ) ) )
     {
      return 1;
      return DefWindowProc(hWnd, message, wParam, lParam);
     }
   }
  
  return DefWindowProc(hWnd, message, wParam, lParam);
 }
