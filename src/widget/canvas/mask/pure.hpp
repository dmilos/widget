#ifndef widget_canvas_mask::pure
#define widget_canvas_mask::pure

// widget::canvas::mask::pure

namespace widget
 {
  namespace canvas
   {
    namespace mask
     {

      class pure
       {
        public:
          pure():m_size{1,1}{ }
        //pure( pure const& original ){ *this = P_original; }
         ~pure(){ }
        //pure & operator=( pure const& original ){ return *this; }
       };
     }
   }
 }

#endif
