#ifndef widget_event_moouse
#define widget_event_moouse

// widget::event::constant::mouse

#include "./keyboard.hpp"




namespace widget
 {
  namespace event
   {
    namespace constant
     {

      enum class mouse
       {
        button_00_up, button_00_down,
        button_01_up, button_01_down,
        button_02_up, button_02_down,
        button_03_up, button_03_down,
        button_04_up, button_04_down,

        wheel_up,
        wheel_down,

        wheel_left_up,  wheel_left_down,
        wheel_right_up, wheel_right_down,
        _end

       };

     }
   }
 }

#endif
