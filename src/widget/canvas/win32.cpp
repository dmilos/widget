#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

#include <algorithm>

#include "./win32.hpp"

::widget::canvas::win32::win32()
 {
  m_dc = nullptr;
  size( { 100, 100 } );
 }

::widget::canvas::win32::~win32()
 {
	DeleteDC(m_dc);
 }


bool
::widget::canvas::win32::size( size2d_type const& p_size )
 {
  HDC ddc = GetDC( NULL );
  HDC cdc = CreateCompatibleDC(ddc);
  HBITMAP hbmp = CreateCompatibleBitmap( ddc, size()[0], size()[1] );

  if( NULL != m_dc )
   {
	  //BitBlt( cdc, 0, 0, std::min<int>(p_size[0], size()[0]), std::min<int>(p_size[1], size()[1]), m_dc, 0, 0, SRCCOPY );
	  DeleteDC(m_dc);
	  m_dc = nullptr;
  }

  m_dc     = cdc;

  size() = p_size;

  return true;
 }

::widget::canvas::win32::pure_type &
::widget::canvas::win32::draw( primitive_type const& element )
 {
	TCHAR greeting[] = _T("Hello, World!");
	TextOut(m_dc, 5, 5, greeting, _tcslen( greeting) );

  /*{
   if( )
    {
	 
    }
  }*/

  /*{
   if( )
    {
	 TextOut(m_cdc,5, 5, greeting, _tcslen(greeting) );
    }
  }*/
  return *this;
 }
