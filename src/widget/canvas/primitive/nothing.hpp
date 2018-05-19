#ifndef widget_primitive_nothing
#define widget_primitive_nothing

// widget::primitive::nothing





#include "./pure.hpp"

namespace widget
 {
  namespace canvas
   {
    namespace primitive
     {

      template< typename size_name, typename position_name, unsigned dimension_number >
       class nothing
        : public ::widget::canvas::primitive::pure< size_name, position_name, dimension_number >
        {
         public:
           typedef ::widget::canvas::primitive::pure<size_name, position_name, dimension_number> pure_type;

         public:
           nothing( ){ }

         public:
           void draw(canvas_type & canvas_param)const { ; }
        };

     }
   }
 }

#endif
