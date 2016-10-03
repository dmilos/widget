#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./xlib.hpp"

#include "../../canvas/native.hpp"


widget::event::generator::xlib::xlib()
 {
  m_run = false;
  m_screen  = -1;
  m_display = nullptr;
 }

widget::event::generator::xlib::~xlib()
 {
  stop();
 }

void widget::event::generator::xlib::element( element_ptr_type element_param )
 {
  element_ptr() = element_param;
  widget::canvas::xlib & canvas = static_cast<widget::canvas::xlib&>( element_param->canvas() );

  canvas.m_screen  = m_screen;
  canvas.m_display = m_display;
  canvas.m_window  = &m_window;

  canvas.size( canvas.size() );
 }

bool widget::event::generator::xlib::run()
 {
  if( true == m_run )
   {
    return true;
   }

  if( nullptr == m_display )
   {
    m_display = XOpenDisplay(NULL);
    if( m_display == NULL )
     {
      return false;
     }

    m_screen = DefaultScreen( m_display );
   }


  m_run = true;
  m_thread = std::thread( &widget::event::generator::xlib::loop, this  );

  return true;
 }

void widget::event::generator::xlib::stop()
 {
  if( false == m_run )
   {
    return;
   }

  if( true == m_thread.joinable() )
   {
    m_thread.join();
   }

  m_run = false;
 }

void widget::event::generator::xlib::loop()
 {
  m_window = XCreateSimpleWindow(m_display, RootWindow(m_display, m_screen), 10, 10, 100, 100, 1,
                          BlackPixel(m_display, m_screen), WhitePixel(m_display, m_screen));
  XSelectInput(m_display, m_window, ExposureMask | KeyPressMask);
  XMapWindow(m_display, m_window);

  XEvent event;
  while (1)
   {
    XNextEvent(m_display, &event);
    if (event.type == Expose)
     {
      GC gc = DefaultGC( m_display, m_screen );
      XFillRectangle( m_display, m_window, gc, 20, 20, 10, 10);
      char const*msg = "Hello, World!";
      XDrawString( m_display, m_window, gc, 10, 50, msg, strlen(msg));
      widget::canvas::xlib & canvas = static_cast<widget::canvas::xlib&>( element_ptr()->canvas() );
      //XCopyArea( m_display, canvas.m_pixmap, m_window, gc, 0, 0, canvas.size()[0], canvas.size()[1], 0, 0);
     }
    if (event.type == KeyPress )
     {
      break;
     }
   }

  XCloseDisplay(m_display);
  m_display = nullptr;
 }