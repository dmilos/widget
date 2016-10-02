#include "./background.hpp"


#if defined( _MSC_VER )
#include "../canvas/win32.hpp"
#endif

#if defined( __GNUC__ )
#include "../canvas/xlib.hpp"
#endif


void
widget::primitive::background::draw( canvas_type & canvas_param )const
 {
#if defined( _MSC_VER )
  widget::canvas::win32 & w32c = static_cast<widget::canvas::win32&>( canvas_param );
  RECT rect{ 0, 0, canvas_param.size()[0]-1, canvas_param.size()[1]-1  };
  HBRUSH brush = CreateSolidBrush( RGB( m_color[0], m_color[1],m_color[2] ) );
  FillRect( w32c.m_dc, &rect, brush );
  DeleteObject( brush );
#endif


 }
