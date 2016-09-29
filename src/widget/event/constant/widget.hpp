#ifndef widget_event_widget
#define widget_event_widget


#include "./mouse.hpp"




namespace widget
 {
  namespace event
   {
    namespace constant
     {

      enum class widget
       {
        _begin = ::widget::event::constant::mouse::_end,

        create,
        destroy,
        hide,

        move,
        size,

        _end

       };

     }
   }
 }

#endif
