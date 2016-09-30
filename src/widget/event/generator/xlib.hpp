#ifndef widget_event_generator_xlib
#define widget_event_generator_xlib

#include "./pure.hpp"
#include "../action.hpp"


namespace widget
 {
  namespace event
   {
    namespace generator
     {

      class xlib
       : public widget::event::generator::pure
       {
        public:
          typedef widget::event::pure event_type;
          typedef widget::event::action_type action_type;

        public:
          xlib( );
          ~xlib();

        protected:
          virtual event_type const& generate();

       };

   }
  }
 }

#endif
