#ifndef widget_window_native
#define widget_window_native

// ::widget::canvas:: native_type

#if defined( _MSC_VER )
#include "./win32.hpp"

namespace widget
 {
  namespace window
   {

    //typedef ::widget::window::win32< widget::type::size_type, widget::type::integer_type, 2 >  native_t, win32_t;

    template< typename size_name, typename position_name, unsigned dimension_number >
     inline void native( ::widget::window::basic< size_name, position_name, dimension_number> &b )
      {
       return ::widget::window::win32( b );
      }

   }
 }

#endif

#if defined( __GNUC__ )
#include "./xlib.hpp"

namespace widget
 {
  namespace window
   {

    //typedef ::widget::window::xlib native, native_t, win32_t;

   }
 }

#endif

#endif
