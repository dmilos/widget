#ifndef widget_window_exchange_process
#define widget_window_exchange_process

// widget::window::exchange::process

#include "../../canvas/pure.hpp"
#include "../../event/generator/pure.hpp"

namespace widget
 {
  namespace window
   {
    namespace exchange
     {
      template< typename size_name, typename position_name, unsigned dimension_number >
       bool process( widget::canvas::pure< size_name, position_name, dimension_number > & c, widget::event::generator::pure & g );

      bool process( widget::canvas::pure< std::size_t, int, 2 > & c, widget::event::generator::pure & g );

     }

   }
 }

#endif
