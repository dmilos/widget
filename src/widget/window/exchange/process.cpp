#include "./process.hpp"


#if defined( _MSC_VER )
#include "./win32.hpp"
#endif


#if defined( __GNUC__ )
#include "./xlib.hpp"
#endif

namespace widget { namespace window { namespace exchange
 {

  namespace prepare
   {

    bool process( widget::canvas::pure< std::size_t, int, 2U > & c, widget::event::generator::pure & g )
     {
    #if defined( _MSC_VER )
      typedef widget::canvas::pure< std::size_t, int, 2U >  canvas_type;
      auto cD = dynamic_cast< ::widget::canvas::win32 * >( &c );
      if( nullptr == cD )
       {
        return false;
       }
      auto gD = dynamic_cast< ::widget::event::generator::win32 *  >( &g );
      if( nullptr == gD )
       {
        return false;
       }

      return widget::window::exchange::prepare::win32( *cD, *gD );
    #endif

    #if defined( __GNUC__ )
      auto cD = dynamic_cast< widget::canvas::xlib & >( c );
      auto gD = dynamic_cast< widget::event::generator::xlib & >( g );

      return widget::window::exchane::xlib( cD, gD );
    #endif

     }

   }

  namespace report
   {

    bool process( widget::canvas::pure< std::size_t, int, 2 > & c, widget::event::generator::pure & g )
     {
    #if defined( _MSC_VER )
      auto cD = dynamic_cast< ::widget::canvas::win32 * >( &c );
      if( nullptr == cD )
       {
        return false;
       }
      auto gD = dynamic_cast< ::widget::event::generator::win32 *  >( &g );
      if( nullptr == gD )
       {
        return false;
       }

      return widget::window::exchange::report::win32(  *cD, *gD );
    #endif

    #if defined( __GNUC__ )
      auto cD = dynamic_cast< widget::canvas::xlib & >( c );
      auto gD = dynamic_cast< widget::event::generator::xlib & >( g );

      return widget::window::exchange::xlib( cD, gD );
    #endif

     }
   }


 } } }
