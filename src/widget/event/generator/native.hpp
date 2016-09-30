#ifndef widget_event_generator_native
#define widget_event_generator_native


#if defined( _MSC_VER )
#include "./win32.hpp"

namespace widget
 {
  namespace event
   {
    namespace generator
     {

      typedef ::widget::event::generator::win32 native;
     }
   }
 }
#endif

#if defined( __GNUC__ )
#include "./xlib.hpp"

namespace widget
 {
  namespace event
   {
    namespace generator
     {
      typedef ::widget::event::generator::xlib native;
     }
   }
 }

#endif

#endif
