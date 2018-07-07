#ifndef widget_window_exchange_win32
#define widget_window_exchange_win32

// widget::window::exchange::win32



#include "../../canvas/win32.hpp"
#include "../../event/generator/win32.hpp"

namespace widget
 {
  namespace window
   {
    namespace exchange
     {

      namespace prepare
       {
        bool win32( widget::canvas::win32 & c, widget::event::generator::win32 & g );
       }

      namespace report
       {
        bool win32( widget::canvas::win32 & c, widget::event::generator::win32 & g );
       }

     }

   }
 }

#endif
