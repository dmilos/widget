#ifndef widget_primitive_pure
#define widget_primitive_pure

// widget::primitive::pure

#include "../canvas/pure.hpp"

namespace widget
 {
  namespace primitive
   {

    class pure
     {
      public:
        typedef widget::canvas::pure canvas_type;

                 pure(){ }
        virtual ~pure(){ }

        virtual void draw( canvas_type & canvas_param )const=0;

     };

   }
 }

#endif
