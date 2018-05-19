#include "./refresh.hpp"


#if defined( _MSC_VER )
#include "../win32.hpp"
#endif

#if defined( __GNUC__ )
#include "../canvas/xlib.hpp"
#endif


void
widget::canvas::primitive::refresh<std::size_t,int,2>::draw( canvas_type & canvas_param )const
 {
#if defined( _MSC_VER )
  widget::canvas::win32 * w32c = dynamic_cast<widget::canvas::win32*>( &canvas_param );
  if( nullptr == w32c )
   {
    return;
   }

  InvalidateRect(w32c->m_hWnd, 0, TRUE);
  //RedrawWindow( w32c->m_hWnd, NULL, NULL, RDW_INTERNALPAINT );
  UpdateWindow( w32c->m_hWnd );
#endif

 }
