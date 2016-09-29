#ifndef widget_canvas_pure
#define widget_canvas_pure

#include "../primitive/pure.hpp"
#include "../type/size.hpp"

namespace widget
 {
  namespace canvas
   {

    class pure
     {
      public:
        typedef ::widget::type::size2d_type size2d_type;
        typedef ::widget::primitive::pure primitive_type;

        pure(){ }
      //pure( pure const& original ){ *this = P_original; }
       ~pure(){ }
      //pure & operator=( pure const& original ){ return *this; }

      public:
        size2d_type    const& size()const{ return m_size; }
        virtual bool         size(  size2d_type const& p_size ){ m_size = p_size; return bool( true ); }
      protected:
        size2d_type        & size(){ return m_size; }
      private:
        size2d_type m_size;

      private:
        virtual void draw( primitive_type const& element )=0;

     };

   }
 }

#endif
