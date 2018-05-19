#ifndef widget_canvas_devnull
#define widget_canvas_devnull

// widget::canvas::devnull





#include "./pure.hpp"

namespace widget
 {
  namespace canvas
   {

    template< typename size_name, typename position_name, unsigned dimension_number >
     class devnull
     : public virtual widget::canvas::pure< std::size_t, int, 2 >
      {
       public:
         typedef widget::canvas::pure< std::size_t, int, 2 > pure_type;

         devnull(){}
        ~devnull(){}
      };

   }
 }

#endif
