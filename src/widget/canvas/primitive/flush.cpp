#include "./flush.hpp"


#if defined( _MSC_VER )
#include "../win32.hpp"
#endif

#if defined( __GNUC__ )
#include "../xlib.hpp"
#endif


void
widget::canvas::primitive::flush<std::size_t,int,2>::draw( canvas_type &canvas_param  )const
 {
#if defined( _MSC_VER )
  GdiFlush();
#endif

#if defined( __GNUC__ )
  //widget::canvas::xlib & xlc = static_cast<widget::canvas::xlib&>( canvas_param );
  //XFlush( xlc.m_display );
#endif

 }
