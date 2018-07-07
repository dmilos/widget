#ifndef widget_window_win32
#define widget_window_win32

// widget::window::win32< size_name, position_name, dimension_number >


#include "./basic.hpp"
#include "../canvas/win32.hpp"
#include "../event/generator/win32.hpp"
#include "../event/consumer/win32.hpp"

namespace widget
 {
  namespace window
   {

    template< typename size_name, typename position_name, unsigned dimension_number >
     inline void win32(  ::widget::window::basic< size_name, position_name, dimension_number> &b )
       {
        b.generator(  new ::widget::event::generator::win32 );

        auto canvas =  new ::widget::canvas::win32;
        b.canvas( canvas );

        auto consumer =  new ::widget::event::consumer::win32;
        consumer->canvas( canvas );
        consumer->window( &b );

        b.consumer( consumer );

        b.generator()->consumer( consumer );
       }

    }
 }

#endif
