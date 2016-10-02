#include "./pixel.hpp"


#if defined( _MSC_VER )
#include "../canvas/win32.hpp"
#endif

#if defined( __GNUC__ )
#include "../canvas/xlib.hpp"
#endif


void
widget::primitive::pixel::draw( canvas_type & canvas_param )const
 {
#if defined( _MSC_VER )
  widget::canvas::win32 & w32c = static_cast<widget::canvas::win32&>( canvas_param );
  SetPixel( w32c.m_dc, m_position[0], m_position[1], RGB( m_color[0], m_color[1],m_color[2] ) );
#endif

 }
