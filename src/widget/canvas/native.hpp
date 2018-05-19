#ifndef widget_canvas_native
#define widget_canvas_native

// ::widget::canvas:: native_type

#if defined( _MSC_VER )
#include "./win32.hpp"

namespace widget
 {
  namespace canvas
   {

    typedef ::widget::canvas::win32 native, native_type, win32_type;

   }
 }
#endif

#if defined( __GNUC__ )
#include "./xlib.hpp"

namespace widget
 {
  namespace canvas
   {

    typedef ::widget::canvas::xlib native, native_type, xlib_type;

   }
 }

#endif

#endif
