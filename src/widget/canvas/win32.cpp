#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

#include <algorithm>

#include "./win32.hpp"


::widget::canvas::win32::win32( )
 {
  m_hWnd   = 0;
  m_dc     = nullptr;
  m_bitmap = nullptr;
  m_hOld   = nullptr;

  this->offset( { 0, 0 } );
  this->size( { 100, 100 } );
 }

::widget::canvas::win32::~win32()
 {
  this->clear();
 }

void
::widget::canvas::win32::clear()
 {
  if( nullptr == this->m_hWnd )
   {
    return;
   }

  if( NULL != m_dc )
   {
    SelectObject( m_dc, m_hOld );
    DeleteObject( m_bitmap );
    DeleteDC( m_dc );
   }

  this->m_hWnd = 0;
  this->m_dc = nullptr;
  this->m_bitmap = nullptr;
  this->m_hOld = nullptr;
 }

bool
::widget::canvas::win32::size( size2d_type const& size_param )
 {
  crop_type::size( size_param );
  if( nullptr == m_hWnd )
   {
    return true;
   }

  HDC ddc        = GetDC( m_hWnd );
  HDC dc         = CreateCompatibleDC( ddc );
  HBITMAP bitmap = CreateCompatibleBitmap( ddc, size_param[0], size_param[1] );

  ReleaseDC( m_hWnd,  ddc );

  HGDIOBJ hOld = SelectObject( dc, bitmap );

  if( NULL != m_dc )
   {
    BitBlt( dc, 0, 0, std::min<int>( size_param[0], size()[0] ), std::min<int>(size_param[1], size()[1] ), m_dc, 0, 0, SRCCOPY );
    SelectObject( m_dc, m_hOld );
    DeleteObject( m_bitmap );
    DeleteDC( m_dc );
   }

  m_dc     = dc;
  m_bitmap = bitmap;
  m_hOld   = hOld;

  return true;
 }

void ::widget::canvas::win32::hWnd( HWND const& hwnd )
 {
  this->clear();
  m_hWnd = hwnd;
  this->size(this->size() );
 }
