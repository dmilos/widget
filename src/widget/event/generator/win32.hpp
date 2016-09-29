#ifndef widget_event_generator_win32
#define widget_event_generator_win32

#include "../action.hpp"
#include "../win32.hpp"

namespace widget
 {
  namespace event
   {
    namespace generator
     {

      class win32
       {
        public:
          typedef widget::event::pure event_type;
          typedef widget::event::action_type action_type;

        public:
          win32( );
          ~win32();

        protected:
          virtual event_type const& generate();

       };

   }
  }
 }

#endif
