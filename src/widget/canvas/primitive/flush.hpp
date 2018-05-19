#ifndef widget_primitive_flush
#define widget_primitive_flush

// widget::primitive::flush





#include "./pure.hpp"

namespace widget
 {
  namespace canvas
    {
    namespace primitive
     {

    template< typename size_name, typename position_name, unsigned dimension_number >
     class flush
      : public ::widget::canvas::primitive::pure< size_name, position_name, dimension_number >
      {
       public:
         flush() {}
       public:
         virtual void draw( canvas_type & canvas_param )const;
      };

     }
   }
 }

#endif
