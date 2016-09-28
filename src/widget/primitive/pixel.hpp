#ifndef widget_primitive_pixel
#define widget_primitive_pixel

#include "../type/point.hpp"

namespace widget
 {
  namespace primitive
   {

    class pixel
     : public widget::primitive::pure
     {
      public:
        typedef ::widget::type::color_t color_type;
        typedef ::widget::type::point_t point_type;

      public:
                 pixel( point_type const& position, color_type const& color )
                  :m_position( position)
                  ,m_color( color )
                  {
                  }

      public:
        point_type m_position;
        color_type m_color;
     };

   }
 }

#endif
