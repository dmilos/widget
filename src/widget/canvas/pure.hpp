#ifndef widget_canvas_pure
#define widget_canvas_pure

// widget::canvas::pure

#include "../type/size.hpp"
#include "../type/position.hpp"

namespace widget
 {
  namespace canvas
   {

    template< typename size_name, typename position_name, unsigned dimension_number >
     class pure
      {
       public:
         typedef ::widget::type::sizeNd_type<         size_name, dimension_number > sizeNd_type;
         typedef ::widget::type::positionNd_type< position_name, dimension_number > positionNd_type;

         typedef widget::canvas::pure< size_name, position_name, dimension_number > pure_type;

         pure()/*:m_size{1,1},m_offset{0,0}*/{ }
       //pure( pure const& original ){ *this = P_original; }
        ~pure(){ }
       //pure & operator=( pure const& original ){ return *this; }

       //public:
       //  sizeNd_type    const& size()const{ return m_size; }
       //  virtual bool          size( sizeNd_type const& size_param ){ m_size = size_param; return bool( true ); }
       //protected:
       //  sizeNd_type         & size_protected(){ return m_size; }
       //private:
       //  sizeNd_type m_size;

       // public:
       //   positionNd_type    const& offset()const{ return m_offset; }
       //   virtual bool              offset(  positionNd_type const& offset_param ){ m_offset = offset_param; return bool( true ); }
       // protected:
       //   positionNd_type         & offset_protected(){ return m_offset; }
       // private:
       //   positionNd_type m_offset;

       public:
         virtual void lock(){  }
         virtual void unlock(){  }
         bool volatile const& status()const { return m_status; }
       private:
         volatile bool m_status;
      };

   }
 }

#endif
