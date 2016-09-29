#ifndef widget_event_moouse
#define widget_event_moouse


#include "./keyboard.hpp"




namespace widget
 {
  namespace event
   {
    namespace constant
     {

      enum class mouse
       {
        _begin = ::widget::event::constant::keyboard::_end,
        button_00_up, button_00_down,
        button_01_up, button_01_down,
        button_02_up, button_02_down,
        button_03_up, button_03_down,
        button_04_up, button_04_down,

        wheel_up_up,   wheel_up_down,
        wheel_down_up, wheel_down_down,

        wheel_left_up,  wheel_left_down,
        wheel_right_up, wheel_right_down,
        _end

       };

     }
   }
 }

#endif
