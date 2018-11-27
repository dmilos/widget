#ifndef widget_event_generator_win32
#define widget_event_generator_win32

// widget::event::generator::win32


#include <windows.h>
#include <thread>

#include "../../window/element/pure.hpp"
#include "./pure.hpp"
#include "../consumer/action.hpp"

#include "../../type/size.hpp"


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
        public:
          HWND const& hWnd()const{ return m_hWnd; }
        private:
           typedef ::widget::window::element::pure< std::size_t, int, 2 > element_type;
           static bool registerClass();
           HWND makeInstance();
           static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );
        private:
          void loop();
        private:
          HWND m_hWnd;
          std::thread   m_thread;
        public:
          widget::type::size2d_type   m_size;
       };

   }
  }
 }

#endif
