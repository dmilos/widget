#include     <X11/Xlib.h>

#include "./xlib.hpp"

::widget::canvas::xlib::xlib()
 {

 }

::widget::canvas::xlib::~xlib()
 {


 }



bool
::widget::canvas::xlib::size(  size2d_type const& p_size )
 {
  /*
  Display *display=XOpenDisplay( NULL );
  Visual *visual=DefaultVisual( display, 0 );

  XImage  *ximage =  XCreateImage( display, visual, 24, ZPixmap, 0, image32, width, height, 32, 0);

  //XDestroyImage( m_ximage );

  ///// XPutImage(display, window, DefaultGC(display, 0), ximage, 0, 0, 0, 0, width, height); 

  Pixmap pixmap = XCreatePixmap( display, ???, width, height, depth )

  //// XCopyPlane(display, m_pixmap, pixmap, DefaultGC(display, 0), 0, 0, width, height, 0, 0, plane )


  XFreePixmap(display, m_pixmap )
  m_pixmap = 0;
  m_pixmap = pixmap;
*/
  return true;
 }

::widget::canvas::xlib::pure_type &
::widget::canvas::xlib::draw( primitive_type const& element )
 {

  {
   /*if( )
    {


    }*/
  }

  return *this;
 }
