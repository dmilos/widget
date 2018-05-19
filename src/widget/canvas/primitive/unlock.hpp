#ifndef widget_primitive_unlock
#define widget_primitive_unlock

// widget::primitive::unlock





#include "./pure.hpp"

namespace widget
 {
  namespace primitive
   {
    template< typename size_name, typename position_name, unsigned dimension_number >
     class unlock
      : public ::widget::canvas::primitive::pure< size_name, position_name, dimension_number >
      {
       public:
     
         public:
         void draw( canvas_type & canvas_param )const;
      };

   }
 }

#endif
