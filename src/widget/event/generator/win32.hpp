#ifndef widget_event_generator_win32
#define widget_event_generator_win32

#include "./pure.hpp"
#include "../action.hpp"


namespace widget
 {
  namespace event
   {
    namespace generator
     {

      class win32
       : public widget::event::generator::pure
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
