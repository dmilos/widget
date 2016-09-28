#ifndef widget_event_action
#define widget_event_action

#include <functional>
#include "./pure.hpp"

namespace widget
 {
  namespace event
   {

    typedef std::function< bool( ::widget::event::pure const& ) > action_type;

   }
}

#endif
