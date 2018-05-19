#include "./circle.hpp"


#if defined( _MSC_VER )
#include "../win32.hpp"
#endif

#if defined( __GNUC__ )
#include "../canvas/xlib.hpp"
#endif


void
widget::canvas::primitive::circle<std::size_t,int,2>::draw( canvas_type & canvas_param )const
 {
#if defined( _MSC_VER )
  widget::canvas::win32 * w32c = dynamic_cast<widget::canvas::win32*>( &canvas_param );
  if( nullptr == w32c )
   {
    return;
   }

  Ellipse( w32c->m_dc, m_centre[0] - m_radius, m_centre[1] - m_radius, m_centre[0] + m_radius, m_centre[1] + m_radius );
#endif
 }
