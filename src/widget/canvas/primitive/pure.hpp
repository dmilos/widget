#ifndef widget_primitive_pure
#define widget_primitive_pure

// ::widget::canvas::primitive::pure< size_name, position_name, dimension_number>
// ::widget::canvas::primitive::pointer< size_name, position_name, dimension_number>

#include <memory>

#include "../pure.hpp"

namespace widget
 {
  namespace canvas
   {
    namespace primitive
     {

      template< typename size_name, typename position_name, unsigned dimension_number >
       class pure
        {
         public:
           typedef widget::canvas::pure<size_name, position_name, dimension_number> canvas_type;

                    pure(){ }
           virtual ~pure(){ }

           virtual void draw( canvas_type & canvas_param )const=0;

        };

     }
   }
 }

#endif
