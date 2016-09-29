#ifndef widget_event_keyboard
#define widget_event_keyboard







namespace widget
 {
  namespace event
   {
    namespace constant
     {

      enum class keyboard
       {
        _begin = 0,

        A_up,  A_down,
        B_up,  B_down,

        shift_up,  shift_down,
        ctrl_up,   ctrl_down,

        space_up,  space_down,
        alt_up,    alt_down,
        OS_up,     OS_down,

        _end

       };

     }
   }
 }

#endif
