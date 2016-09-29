#ifndef widget_canvas_xlib
#define widget_canvas_xlib

// widget::canvas::xlib

#include "./pure.hpp"

namespace widget
 {
  namespace canvas
   {

    class xlib
    : public widget::canvas::pure
     {
      public:
        typedef ::widget::type::size2d_type size2d_type;
        typedef ::widget::primitive::pure primitive_type;
        
        typedef widget::canvas::pure pure_type; 

        xlib();
      //pure( pure const& original ){ *this = P_original; }
       ~xlib();
      //pure & operator=( pure const& original ){ return *this; }

      public:
        bool          size(  size2d_type const& p_size );

      public:
        pure_type & draw( primitive_type const& element ) =0;

     };

   }
 }

#endif
