#ifndef widget_event_generator_xlib
#define widget_event_generator_xlib
#include <thread>
#include <X11/Xlib.h>

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

        public:
          void element( element_ptr_type element_param );
        public:
          bool run();
          void stop();

        private:
          void loop();
        public:
          volatile bool m_run;
          std::thread   m_thread;

          Display *m_display;
          int      m_screen;
          Window   m_window;
       };

   }
  }
 }

#endif
