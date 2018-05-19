#ifndef widget_canvas_xlib
#define widget_canvas_xlib

// widget::canvas::xlib

#include <X11/Xlib.h>



#include "./pure.hpp"

namespace widget
 {
  namespace canvas
   {

    class xlib
    : public virtual widget::canvas::pure< std::size_t, int, 2 >
     {
      public:
        typedef widget::canvas::pure< std::size_t, int, 2 > pure_type;

        typedef pure_type::sizeNd_type size2d_type;

        xlib();
      //pure( pure const& original ){ *this = P_original; }
       ~xlib();
      //pure & operator=( pure const& original ){ return *this; }

      public:
        using pure_type::size;
        bool          size( size2d_type const& p_size );
      public:
        Display  *m_display;
        int       m_screen;
        Window   *m_window;
        Pixmap    m_pixmap;

     };

   }
 }

#endif
