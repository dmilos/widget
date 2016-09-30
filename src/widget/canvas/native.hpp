#ifndef widget_canvas_native
#define widget_canvas_native

#if defined( _MSC_VER )
#include "./win32.hpp"

namespace widget
 {
  namespace canvas
   {
    typedef ::widget::canvas::win32 native;
   }
 }
#endif

#if defined( __GNUC__ )
#include "./xlib.hpp"

namespace widget
 {
  namespace canvas
   {
    typedef ::widget::canvas::xlib native;
   }
 }

#endif

#endif
