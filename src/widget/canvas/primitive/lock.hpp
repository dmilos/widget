#ifndef widget_primitive_lock
#define widget_primitive_lock

// widget::primitive::lock





#include "./pure.hpp"

namespace widget
 {
  namespace primitive
   {

    template< typename size_name, typename position_name, unsigned dimension_number >
     class lock
      : public ::widget::canvas::primitive::pure< size_name, position_name, dimension_number >
      {
       public:
     
       public:
         virtual void draw( canvas_type & canvas_param )const;
      };

   }
 }

#endif
