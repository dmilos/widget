#include "./pixel.hpp"


#if defined( _MSC_VER )
#include "../win32.hpp"
#endif

#if defined( __GNUC__ )
#include "../xlib.hpp"
#endif


void
widget::primitive::pixel<std::size_t, int, 2>::draw( canvas_type & canvas_param )const
 {
#if defined( _MSC_VER )
  widget::canvas::win32 * w32c = dynamic_cast<widget::canvas::win32*>( &canvas_param );

  if( nullptr == w32c )
   {
    return;
   }

  SetPixel( w32c->m_dc, m_position[0], m_position[1], RGB( m_color[0], m_color[1],m_color[2] ) );
#endif

 }
