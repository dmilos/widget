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
        auto w32generator = new ::widget::event::generator::win32{};
        b.generator( w32generator );
        auto w32canvas = new ::widget::canvas::win32{};
        b.canvas(   w32canvas );
        auto w32consumer = new ::widget::event::consumer::win32{};
        b.consumer( w32consumer );

        w32consumer->canvas( w32canvas );
        w32generator->consumer( w32consumer );
       }

    }
 }

#endif
