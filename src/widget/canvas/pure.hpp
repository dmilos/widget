#ifndef widget_canvas_pure
#define widget_canvas_pure

// widget::canvas::pure

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
        typedef ::widget::type::position2d_type position2d_type;
        typedef ::widget::primitive::pure primitive_type;

        typedef widget::canvas::pure pure_type;

        pure():m_size{1,1}{ }
      //pure( pure const& original ){ *this = P_original; }
       ~pure(){ }
      //pure & operator=( pure const& original ){ return *this; }

      public:
        size2d_type    const& size()const{ return m_size; }
        virtual bool          size(  size2d_type const& p_size ){ m_size = p_size; return bool( true ); }
      protected:
        size2d_type         & size(){ return m_size; }
      private:
        size2d_type m_size;

      public:
        position2d_type    const& offset()const{ return m_offset; }
        virtual bool              offset(  position2d_type const& p_offset ){ m_offset = p_offset; return bool( true ); }
      protected:
        position2d_type         & offset(){ return m_offset; }
      private:
        position2d_type m_offset;

      public:
        virtual pure_type & draw( primitive_type const& element ) =0;

     };

   }
 }

#endif
