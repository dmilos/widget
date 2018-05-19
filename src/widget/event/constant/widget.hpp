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
        pre_create,

        create,
        destroy,

        hide,
        max,

        move,
        size,

        _end

       };

     }
   }
 }

#endif
