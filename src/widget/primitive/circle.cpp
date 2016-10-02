#include "./circle.hpp"


#if defined( _MSC_VER )
#include "../canvas/win32.hpp"
#endif

#if defined( __GNUC__ )
#include "../canvas/xlib.hpp"
#endif


void
widget::primitive::circle::draw( canvas_type & canvas_param )const
 {
#if defined( _MSC_VER )
  widget::canvas::win32 & w32c = static_cast<widget::canvas::win32&>( canvas_param );
  Ellipse( w32c.m_dc, m_centre[0] - m_radius, m_centre[1] - m_radius, m_centre[0] + m_radius, m_centre[1] + m_radius );
#endif
 }
