#ifndef widget_window_exchange_xlib
#define widget_window_exchange_xlib

// widget::window::exchange::xlib



#include "../../canvas/xlib.hpp"
#include "../../event/generator/xlib.hpp"

namespace widget
 {
  namespace window
   {
    namespace exchange
     {

      namespace prepare
       {
        bool xlib( widget::canvas::xlib & c, widget::event::generator::xlib & g );
       }

      namespace report
       {
        bool xlib( widget::canvas::xlib & c, widget::event::generator::xlib & g );
       }

     }

   }
 }

#endif
