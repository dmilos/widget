#include     <X11/Xlib.h>

#include "./xlib.hpp"

::widget::canvas::xlib::xlib()
 {
  m_display = nullptr;;
  m_screen = 0;
  m_window = nullptr;
  m_pixmap = 0;
 }

::widget::canvas::xlib::~xlib()
 {
 }

bool
::widget::canvas::xlib::size( size2d_type const& size_param )
 {
  if( nullptr == m_display )
   {
    return false;
   }

  XWindowAttributes attribute;
  XGetWindowAttributes( m_display, *m_window, &attribute );

  m_pixmap = XCreatePixmap( m_display, *m_window, size_param[0], size_param[1], attribute.depth );

  //if( m_pixmap.x11 )
   {

   }

  return true;
 }
