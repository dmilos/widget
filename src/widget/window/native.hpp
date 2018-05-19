#ifndef widget_window_native
#define widget_window_native

// ::widget::canvas:: native_type

#if defined( _MSC_VER )
#include "./win32.hpp"

namespace widget
 {
  namespace window
   {

    typedef ::widget::window::win32< std::size_t, int, 2 > native, native_type, win32_type;

   }
 }
#endif

#if defined( __GNUC__ )
#include "./xlib.hpp"

namespace widget
 {
  namespace window
   {

    typedef ::widget::window::xlib native, native_type, xlib_type;

   }
 }

#endif

#endif
