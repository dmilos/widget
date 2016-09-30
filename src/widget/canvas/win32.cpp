#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

#include <algorithm>

#include "./win32.hpp"
#include "../primitive/text.hpp"

::widget::canvas::win32::win32()
 {
  m_dc = nullptr;
  m_bitmap = nullptr;
  m_hOld = nullptr;

  offset( { 0, 100 } );
  size( { 100, 100 } );
 }

::widget::canvas::win32::~win32()
 {
  if( NULL != m_dc )
   {
    SelectObject( m_dc, m_hOld );
    DeleteObject( m_bitmap);
    DeleteDC( m_dc );
   }
 }


bool
::widget::canvas::win32::size( size2d_type const& size_param )
 {
  HDC ddc = GetDC( NULL );
  HDC dc = CreateCompatibleDC(ddc);
  HBITMAP bitmap = CreateCompatibleBitmap( dc, size_param[0], size_param[1] );
  HGDIOBJ hOld = SelectObject( dc, bitmap );

  if( NULL != m_dc )
   {
    BitBlt( dc, 0, 0, std::min<int>( size_param[0], size()[0] ), std::min<int>(size_param[1], size()[1]), m_dc, 0, 0, SRCCOPY );
    SelectObject( m_dc, m_hOld );
    DeleteObject(m_bitmap);
    DeleteDC( m_dc );
   }

  m_dc     = dc;
  m_bitmap = bitmap;
  m_hOld    = hOld;

  size() = size_param;

  return true;
 }

::widget::canvas::win32::pure_type &
::widget::canvas::win32::draw( primitive_type const& element )
 {
  {
   widget::primitive::text const* text = dynamic_cast<widget::primitive::text const*>( &element );
   if( nullptr != text )
    {
     TextOutA( m_dc, text->m_position[0], text->m_position[1], text->m_content.c_str(), text->m_content.size() );
    }
  }

  return *this;
 }
