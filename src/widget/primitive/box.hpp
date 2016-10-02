#ifndef widget_primitive_box
#define widget_primitive_box

#include "../type/color.hpp"
#include "../type/position.hpp"


#include "./pure.hpp"

namespace widget
 {
  namespace primitive
   {

    class box
     : public ::widget::primitive::pure
     {
      public:
        typedef ::widget::type::color_type  color_type;
        typedef ::widget::type::position2d_type position2d_type;

      public:
                 box( position2d_type const& lo, position2d_type const & hi, color_type const& color )
                  :m_color( color )
                  ,m_lo( lo )
                  ,m_hi( hi )
                  { 
                  }

      public:
        void draw( canvas_type & canvas_param )const;
      public:
        position2d_type m_lo; 
        position2d_type m_hi;
        color_type      m_color;
     };

   }
 }

#endif
