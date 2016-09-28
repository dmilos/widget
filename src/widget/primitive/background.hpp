#ifndef widget_primitive_background
#define widget_primitive_background

#include "../type/color.hpp"

namespace widget
 {
  namespace primitive
   {

    class background
     : public widget::primitive::pure
     {
      public:
        typedef ::widget::primitive::type::color_t color_type;

      public:
                 background( color_type const& color ):m_color( color ){ }

      public:
        color_type m_color;
     };

   }
 }

#endif
