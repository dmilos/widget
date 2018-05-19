#include "./process.hpp"


#if defined( _MSC_VER )
#include "./win32.hpp"
#endif


#if defined( __GNUC__ )
#include "./xlib.hpp"
#endif

namespace widget { namespace window { namespace exchange
 {
  bool process( widget::canvas::pure< std::size_t, int, 2 > & c, widget::event::generator::pure & g )
   {
  #if defined( _MSC_VER )
    auto cD = dynamic_cast< ::widget::canvas::win32 * >( &c );
    auto gD = dynamic_cast< ::widget::event::generator::win32 *  >( &g );
  
    return widget::window::exchane::win32(  *cD, *gD );
  #endif
  
  #if defined( __GNUC__ )
    auto cD = dynamic_cast< widget::canvas::xlib & >( c );
    auto gD = dynamic_cast< widget::event::generator::xlib & >( g );
  
    return widget::window::exchane::win32( cD, gD );
  #endif
  
   }

 } } }