#ifndef widget_element_pure
#define widget_element_pure

// widget::element::pure

#include <set>

#include "../type/size.hpp"

#include "../event/consumer/simple.hpp"

#include "../type/dumb.hpp"
#include "../canvas/pure.hpp"
#include "../primitive/pure.hpp"


namespace widget
 {
  namespace element
   {

    class pure
     {
      public:

        typedef ::widget::canvas::pure canvas_type;
        typedef ::widget::type::dumb_ptr<canvas_type> canvas_ptr_type;

        typedef ::widget::event::consumer::simple consumer_type;
        typedef ::widget::type::dumb_ptr<consumer_type> consumer_ptr_type;

        typedef ::widget::primitive::pure  primitive_type;

        typedef ::widget::element::pure  pure_type;
        typedef ::widget::type::dumb_ptr<pure_type> ptr_type;
        typedef std::set< ptr_type > container_type;

        pure( ptr_type const& parent = nullptr )
         : m_consumer( nullptr )
         , m_parent( parent  )
         , m_canvas( nullptr )
         {
         }
      //pure( pure const& original ){ *this = P_original; }
       ~pure(){ }
      //pure & operator=( pure const& original ){ return *this; }

      public:
        consumer_type    const& consumer()const{ return *m_consumer; }
        consumer_type         & consumer()     { return *m_consumer; }
      protected:
        consumer_ptr_type     & consumer_ptr() { return m_consumer; }
      private:
        consumer_ptr_type m_consumer;

      public:
        ptr_type    const& parent()const{ return m_parent; }
        virtual bool       parent(  ptr_type const& p_parent ){ m_parent = p_parent; return bool( true ); }
      protected:
        ptr_type        & parent(){ return m_parent; }
      private:
        ptr_type m_parent;

      public:
        container_type    const& child()const{ return m_child; }
        virtual bool       attach(  ptr_type child )
         {
          m_child.insert( child ); 
          child->parent( this ); 
          return bool( true ); 
         }
      protected:
        container_type        & child(){ return m_child; }
      private:
        container_type m_child;

      public:
        canvas_type    const& canvas()const{ return *m_canvas; }
        canvas_type         & canvas()     { return *m_canvas; }
        pure_type         & draw( primitive_type const& primitive_param ) { primitive_param.draw( *m_canvas );  return *this; }
      protected:
        canvas_ptr_type     & canvas_ptr()     { return m_canvas; }
      private:
        canvas_ptr_type m_canvas;

     };

   }
 }

#endif

