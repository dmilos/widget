#ifndef widget_event_list
#define widget_event_list

namespace widget
 {
  namespace event
   {

    enum list
     {
      mouse__begin,
      mouse_button_00_up, mouse_button_00_down,
      mouse_button_01_up, mouse_button_01_down,
      mouse_button_02_up, mouse_button_02_down,
      mouse_button_03_up, mouse_button_03_down,
      mouse_button_04_up, mouse_button_04_down,

      mouse_wheel_up_up,   mouse_wheel_up_down,
      mouse_wheel_down_up, mouse_wheel_down_down,

      mouse_wheel_left_up,  mouse_wheel_left_down,
      mouse_wheel_right_up, mouse_wheel_right_down,
      mouse__end,

      keyboard_begin,
      keyboard_A_up,  keyboard_A_down,
      keyboard_B_up,  keyboard_B_down,

      keyboard_shift_up,  keyboard_shift_down,
      keyboard_ctrl_up,   keyboard_ctrl_down,

      keyboard_space_up,  keyboard_space_down,
      keyboard_alt_up,    keyboard_alt_down,
      keyboard_OS_up,     keyboard_OS_down,

      keyboard__end

     };

   }
}

#endif
