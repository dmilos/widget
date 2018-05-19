#include "./background.hpp"


#if defined( _MSC_VER )
#include "../win32.hpp"
#endif

#if defined( __GNUC__ )
#include "../canvas/xlib.hpp"
#endif


void
widget::canvas::primitive::background<std::size_t,int,2>::draw( canvas_type & canvas_param )const
 {
#if defined( _MSC_VER )
  widget::canvas::win32 * w32c = dynamic_cast<widget::canvas::win32*>( &canvas_param );
  if( nullptr == w32c )
   {
    return;
   }

  RECT rect{ 0, 0, w32c->size()[0]-1, w32c->size()[1]-1  };
  //RECT rect{ 0, 0, 1000, 1000  };
  HBRUSH brush = CreateSolidBrush( RGB( m_color[0], m_color[1],m_color[2] ) );
  FillRect( w32c->m_dc, &rect, brush );
  DeleteObject( brush );
#endif

 }
