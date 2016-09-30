#ifndef widget_event_generator_win32
#define widget_event_generator_win32

#include <windows.h>
#include <thread>


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

	   public:
		   bool run();
		   void stop();

	   private:
		   static bool registerClass();
		   static HWND makeInstance();
		   static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );
	   private:
		   void loop();
	   private:
		   HWND m_hWnd;
		   volatile bool m_run;
		   std::thread m_thread;

       };

   }
  }
 }

#endif
