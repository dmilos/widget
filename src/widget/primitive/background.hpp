#ifndef widget_primitive_background
#define widget_primitive_background

#include "../type/color.hpp"



#include "./pure.hpp"

namespace widget
 {
  namespace primitive
   {

    class background
     : public ::widget::primitive::pure
     {
      public:
        typedef ::widget::type::color_type  color_type;

      public:
                 background( color_type const& color ):m_color( color ){ }

      public:
        color_type m_color;
     };

   }
 }

#endif
