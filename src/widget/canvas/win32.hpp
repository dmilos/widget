#ifndef widget_canvas_win32
#define widget_canvas_win32

#include <windows.h>

// widget::canvas::win32

#include "./pure.hpp"

namespace widget
 {
  namespace canvas
   {

    class win32
    : public widget::canvas::pure
     {
      public:
        typedef ::widget::type::size2d_type size2d_type;
        typedef ::widget::primitive::pure primitive_type;

        typedef widget::canvas::pure pure_type;

        win32();
      //pure( pure const& original ){ *this = P_original; }
       ~win32();
      //pure & operator=( pure const& original ){ return *this; }

      public:
        using pure_type::size;
        bool          size(  size2d_type const& p_size );

      public:
		  pure_type & draw(primitive_type const& element);
      public:
		HDC     m_dc;
     };

   }
 }

#endif
