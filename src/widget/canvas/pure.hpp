#ifndef widget_canvas_pure
#define widget_canvas_pure

// widget::canvas::pure

#include "../type/size.hpp"
#include "../type/position.hpp"

namespace widget
 {
  namespace canvas
   {

    class pure
     {
      public:
        typedef ::widget::type::size2d_type size2d_type;
        typedef ::widget::type::position2d_type position2d_type;

        typedef widget::canvas::pure pure_type;

        pure():m_size{1,1},m_offset{0,0}{ }
      //pure( pure const& original ){ *this = P_original; }
       ~pure(){ }
      //pure & operator=( pure const& original ){ return *this; }

      public:
        size2d_type    const& size()const{ return m_size; }
        virtual bool          size(  size2d_type const& size_param ){ m_size = size_param; return bool( true ); }
      protected:
        size2d_type         & size_protected(){ return m_size; }
      private:
        size2d_type m_size;

      public:
        position2d_type    const& offset()const{ return m_offset; }
        virtual bool              offset(  position2d_type const& offset_param ){ m_offset = offset_param; return bool( true ); }
      protected:
        position2d_type         & offset_protected(){ return m_offset; }
      private:
        position2d_type m_offset;

      public:
        virtual void lock(){  }
        virtual void unlock(){  }
        bool volatile const& status()const { return m_status; }
      private:
        volatile bool m_status;

      // TODO public:
      // TODO   mask_type      & mask(){ return m_mask; }
      // TODO   mask_type const& mask()const{ return m_mask; }
      // TODO protected:
      // TODO   mask_type         & mask(){ return m_mask; }
      // TODO private:
      // TODO   mask_type m_mask;
     };

   }
 }

#endif
