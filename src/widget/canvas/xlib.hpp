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
    : public virtual widget::canvas::pure< ::widget::type::size_type, ::widget::type::integer_type, 2 >
     {
      public:
        typedef ::widget::type::integer_type integer_type;
        typedef ::widget::type::size_type      size_type;


        typedef widget::canvas::pure< ::widget::type::size_type, ::widget::type::integer_type, 2 > pure_type;

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
