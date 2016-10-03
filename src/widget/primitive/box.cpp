#include "./box.hpp"


#if defined( _MSC_VER )
#include "../canvas/win32.hpp"
#endif

#if defined( __GNUC__ )
#include "../canvas/xlib.hpp"
#endif


void
widget::primitive::box::draw( canvas_type & canvas_param )const
 {
#if defined( __GNUC__ )
      //widget::canvas::xlib & xlc = static_cast<widget::canvas::xlib&>( canvas_param );

      //XFillRectangle( xlc.m_display, xlc.m_window, DefaultGC( xlc.m_display, xlc.m_screen), m_lo[0], m_lo[1], m_hi[0]-m_lo[0]+1, m_hi[1] - m_lo[1]+1 );
#endif



 }
