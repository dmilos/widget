#include <algorithm>
#include "./win32.hpp"

::widget::canvas::win32::win32()
 {
  m_bitmap = nullptr;
  size( { 100, 100 } );
 }

::widget::canvas::win32::~win32()
 {
  DeleteObject( m_bitmap );
  m_bitmap = 0;
 }


bool
::widget::canvas::win32::size( size2d_type const& p_size )
 {
  HDC ddc = GetDC( NULL );
  HDC cdc = CreateCompatibleDC(ddc);

  HBITMAP hbmp = CreateCompatibleBitmap( ddc, size()[0], size()[1] );

  p_size[0], size()[0] ;
  
  //BitBlt( hbmp, 0, 0, std::min( p_size[0], size()[0] ), std::min( p_size[1], size()[1] ), m_bitmap, 0, 0, SRCCOPY );

  DeleteObject( m_bitmap );
  m_bitmap = 0;

  m_bitmap = hbmp;
  size() = p_size;

  return true;
 }

::widget::canvas::win32::pure_type &
::widget::canvas::win32::draw( primitive_type const& element )
 {
  /*{
   if( )
    {
     Ellipse( m_cdc,0, 0, 100, 100 );
    }
  }*/

  return *this;
 }
