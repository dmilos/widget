#include "./text.hpp"


#if defined( _MSC_VER )
#include "../win32.hpp"
#endif

#if defined( __GNUC__ )
#include "../xlib.hpp"
#endif


void
widget::canvas::primitive::text<std::size_t, int, 2>::draw( canvas_type & canvas_param )const
 {
#if defined( _MSC_VER )
  widget::canvas::win32 * w32c = dynamic_cast<widget::canvas::win32*>( &canvas_param );
  if( nullptr == w32c )
   {
    return;
   }

  SetTextColor( w32c->m_dc, RGB( m_color[0], m_color[1],m_color[2] ) );
  SetBkColor( w32c->m_dc, RGB( 0, 0, 0 ) );
  SetBkMode( w32c->m_dc, TRANSPARENT );
  TextOutA( w32c->m_dc, m_position[0], m_position[1], m_content.c_str(), m_content.size() );
#endif

#if defined( __GNUC__ )
      //widget::canvas::xlib & xlc = static_cast<widget::canvas::xlib&>( canvas_param );

      //XDrawString( xlc.m_display, xlc.m_window, DefaultGC( xlc.m_display, xlc.m_screen), m_position[0], m_position[1], m_content.c_str(), m_content.size() );
#endif

 }
