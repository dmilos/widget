#ifndef widget_primitive_circle
#define widget_primitive_circle

#include "../type/point.hpp"
#include "../type/color.hpp"
#include "../type/scalar.hpp"

namespace widget
 {
  namespace primitive
   {

    class circle
     : public widget::primitive::pure
     {
      public:
        typedef ::widget::type::color_ttpe   color_type;
        typedef ::widget::type::point_type   point_type;
        typedef ::widget::type::scalar_type scalar_type;

      public:
                 circle( point_type const& centre, scalar_type const& radius, color_type const& color )
                  :m_position( position )
                  ,m_radius( radius )
                  ,m_color( color )
                  {
                  }

      public:
        point_type  m_position;
        scalar_type m_radius;
        color_type  m_color;
     };

   }
 }

#endif
