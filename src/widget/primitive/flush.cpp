#include "./flush.hpp"


#if defined( _MSC_VER )
#include "../canvas/win32.hpp"
#endif

#if defined( __GNUC__ )
#include "../canvas/xlib.hpp"
#endif


void
widget::primitive::flush::draw( canvas_type &canvas_param  )const
 {
#if defined( _MSC_VER )
  GdiFlush();
#endif

#if defined( __GNUC__ )
  //widget::canvas::xlib & xlc = static_cast<widget::canvas::xlib&>( canvas_param );
  //XFlush( xlc.m_display );

#endif





 }
