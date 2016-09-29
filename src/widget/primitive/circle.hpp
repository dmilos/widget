#ifndef widget_primitive_circle
#define widget_primitive_circle

#include "../type/position.hpp"
#include "../type/color.hpp"
#include "../type/scalar.hpp"

#include "./pure.hpp"

namespace widget
 {
  namespace primitive
   {

    class circle
     : public ::widget::primitive::pure
     {
      public:
        typedef ::widget::type::color_type  color_type;
        typedef ::widget::type::position2d_type position2d_type;
        typedef ::widget::type::scalar_type scalar_type;

      public:
                 circle( position2d_type const& centre, scalar_type const& radius, color_type const& color )
                  :m_position( centre )
                  ,m_radius( radius )
                  ,m_color( color )
                  {
                  }

      public:
        position2d_type  m_position;
        scalar_type m_radius;
        color_type  m_color;
     };

   }
 }

#endif
