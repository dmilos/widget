#include "./text.hpp"


#if defined( _MSC_VER )
#include "../canvas/win32.hpp"
#endif

#if defined( __GNUC__ )
#include "../canvas/xlib.hpp"
#endif


void
widget::primitive::text::draw( canvas_type & canvas_param )const
 {
#if defined( _MSC_VER )
  widget::canvas::win32 & w32c = static_cast<widget::canvas::win32&>( canvas_param );
  SetTextColor( w32c.m_dc, RGB( m_color[0], m_color[1],m_color[2] ) );
  SetBkColor( w32c.m_dc,   RGB( 255, 255, 255) );

  TextOut( w32c.m_dc, m_position[0], m_position[1], m_content.c_str(), m_content.size() );
#endif
 }
