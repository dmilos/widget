#ifndef widget_primitive_box
#define widget_primitive_box

#include "../../type/color.hpp"
#include "../../type/position.hpp"


#include "./pure.hpp"

namespace widget
 {
  namespace primitive
   {

	template< typename size_name, typename position_name, unsigned dimension_number >
     class box
      : public ::widget::canvas::primitive::pure< size_name, position_name, dimension_number >
      {
       public:
         typedef ::widget::canvas::primitive::pure<size_name, position_name, dimension_number> pure_type;
         typedef ::widget::type::color_type  color_type;
         typedef ::widget::type::positionNd_type<position_name, dimension_number> positionNd_type;

       public:
         box()
          {
          }
         box( positionNd_type const& lo, positionNd_type const & hi, color_type const& color )
          :m_color( color )
          ,m_lo( lo )
          ,m_hi( hi )
          { 
          }
 
       public:
         void draw( canvas_type & canvas_param )const;
       public:
         positionNd_type m_lo;
         positionNd_type m_hi;
         color_type      m_color;
      };

   }
 }

#endif
