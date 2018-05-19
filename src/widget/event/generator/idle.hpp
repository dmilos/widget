#ifndef widget_event_generator_idle
#define widget_event_generator_idle

// ::widget::event::generator::idle

#include "./pure.hpp"


namespace widget
 {
  namespace event
   {
    namespace generator
     {

      class idle
       : public widget::event::generator::pure
       {
        public:
          typedef widget::event::pure event_type;

        public:
           idle()
            {
            }
          ~idle()
           {
            this->stop();
           }

        public:
          bool run()
           {
            this->active_protected().store( true );
            return true;
           }
          void stop()
           {
            this->active_protected().store( false );
           }
       };

   }
  }
 }

#endif
