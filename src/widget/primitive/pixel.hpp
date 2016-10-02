#ifndef widget_primitive_pixel
#define widget_primitive_pixel

#include "../type/color.hpp"
#include "../type/position.hpp"
#include "./pure.hpp"


#include "./pure.hpp"

namespace widget
 {
  namespace primitive
   {

    class pixel
     : public ::widget::primitive::pure
     {
      public:
        typedef ::widget::type::color_type  color_type;
        typedef ::widget::type::position2d_type position2d_type;

      public:
                 pixel( position2d_type const& position, color_type const& color )
                  :m_position( position )
                  ,m_color( color )
                  {
                  }

      public:
        void draw( canvas_type & canvas_param )const;
      public:
        position2d_type m_position;
        color_type      m_color;
     };

   }
 }

#endif
