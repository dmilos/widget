#ifndef widget_event_generator_win32
#define widget_event_generator_win32

// widget::event::generator::win32


#include <windows.h>
#include <thread>

#include "../../window/element/pure.hpp"
#include "./pure.hpp"
#include "../action.hpp"


namespace widget
 {
  namespace event
   {
    namespace generator
     {

      class win32
       : public virtual widget::event::generator::pure
       {
        public:
          typedef widget::event::pure event_type;
          typedef widget::event::consumer::action_type action_type;

        public:
           win32();
          ~win32();

        public:
          void consumer( consumer_ptr_type consumer_param );
        public:
          bool run();
          void stop();

        private:
           typedef ::widget::window::element::pure< std::size_t, int, 2 > element_type;
           static bool registerClass();
           HWND makeInstance();
           static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );
        private:
          void loop();
        public:
          HWND m_hWnd;
          std::thread   m_thread;
       };

   }
  }
 }

#endif
