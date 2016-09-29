#ifndef widget_element_basic
#define widget_element_basic

// widget::element::basic

#include "./pure.hpp"


namespace widget
 {
  namespace element
   {

    class basic 
    : public widget::element::pure
     {
      public:

        basic(){ }
      //pure( pure const& original ){ *this = P_original; }
       ~basic(){ }
      //pure & operator=( pure const& original ){ return *this; }


     };

   }
 }

#endif

