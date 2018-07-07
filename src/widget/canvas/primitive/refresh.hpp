#ifndef widget_primitive_refresh
#define widget_primitive_refresh

// widget::primitive::refresh

#include "../../type/color.hpp"



#include "./pure.hpp"

namespace widget
 {
  namespace canvas
    {
    namespace primitive
     {

      template< typename size_name, typename position_name, unsigned dimension_number >
       class refresh
        : public ::widget::canvas::primitive::pure< size_name, position_name, dimension_number >
        {
         public:
           typedef ::widget::type::color_type  color_type;

           typedef ::widget::canvas::primitive::pure<size_name, position_name, dimension_number> pure_type;

         public:
           refresh( ){ }

         public:
           void draw( canvas_type & canvas_param)const;
        };

     }
   }
 }

#endif
