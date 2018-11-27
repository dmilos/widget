#ifndef widget_event_action
#define widget_event_action

// ::widget::event::consumer::action_type

#include <functional>
#include "./pure.hpp"

namespace widget
 {
  namespace event
   {
    namespace consumer
     {

      typedef std::function< bool( ::widget::event::pure const& ) > action_type;

     }
   }
 }

#endif
