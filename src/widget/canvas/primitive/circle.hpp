#ifndef widget_primitive_circle
#define widget_primitive_circle

// widget::primitive::circle

#include "../../type/position.hpp"
#include "../../type/color.hpp"
#include "../../type/scalar.hpp"

#include "./pure.hpp"

namespace widget
 {
  namespace canvas
   {
    namespace primitive
     {

      template< typename size_name, typename position_name, unsigned dimension_number >
       class circle
        : public ::widget::canvas::primitive::pure< size_name, position_name, dimension_number >
        {
         public:
           typedef ::widget::canvas::primitive::pure<size_name, position_name, dimension_number> pure_type;
           typedef ::widget::type::color_type  color_type;
           typedef ::widget::type::positionNd_type<position_name, dimension_number> positionNd_type;

           typedef ::widget::type::scalar_type scalar_type;
      
         public:
                    circle( positionNd_type const& centre, scalar_type const& radius, color_type const& color = color_type{} )
                     :m_centre( centre )
                     ,m_radius( radius )
                     ,m_color( color )
                     {
                     }
      
         public:
           void draw( canvas_type & canvas_param )const;
         public:
           positionNd_type  m_centre;
           scalar_type m_radius;
           color_type  m_color;
        };


     }
   }
 }

#endif
