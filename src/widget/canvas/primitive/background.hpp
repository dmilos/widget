#ifndef widget_primitive_background
#define widget_primitive_background

// widget::primitive::background

#include "../../type/color.hpp"



#include "./pure.hpp"

namespace widget
 {
  namespace canvas
    {
    namespace primitive
     {

      template< typename size_name, typename position_name, unsigned dimension_number >
       class background
        : public ::widget::canvas::primitive::pure< size_name, position_name, dimension_number >
        {
         public:
           typedef ::widget::type::color_type  color_type;

           typedef ::widget::canvas::primitive::pure<size_name, position_name, dimension_number> pure_type;
           typedef typename pure_type::canvas_type::positionNd_type positionNd_type;

         public:
           background( color_type const& color ):m_color( color ){ }

         public:
            void draw(canvas_type & canvas_param)const;
         public:
           color_type m_color;
        };

     }
   }
 }

#endif
