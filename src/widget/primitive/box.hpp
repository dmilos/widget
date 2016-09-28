#ifndef widget_primitive_box
#define widget_primitive_box

#include "../type/color.hpp"
#include "../type/point.hpp"

namespace widget
 {
  namespace primitive
   {

    class box
     : public widget::primitive::pure
     {
      public:
        typedef ::widget::type::color_t color_type;
        typedef ::widget::type::point_t point_type;

      public:
                 box( point_type const& lo, point_type const & hi, color_type const& color )
                  :m_color( color )
                  ,m_lo( lo )
                  ,m_hi( hi )
                  { 
                  }

      public:
        point_type m_lo; 
        point_type m_hi;
        color_type m_color;
     };

   }
 }

#endif
