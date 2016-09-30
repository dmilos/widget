#ifndef widget_element_pure
#define widget_element_pure

// widget::element::pure

#include <set>

#include "../type/size.hpp"

#include "../event/engine/pure.hpp"

#include "../type/dumb.hpp"
#include "../canvas/pure.hpp"


namespace widget
 {
  namespace element
   {

    class pure
     {
      public:

        typedef ::widget::canvas::pure canvas_type;
        typedef ::widget::type::dumb_ptr<canvas_type> canvas_ptr_type;

        typedef ::widget::event::engine::pure engine_type;
        typedef ::widget::type::dumb_ptr<engine_type> engine_ptr_type;

        typedef ::widget::element::pure  pure_type;
        typedef ::widget::type::dumb_ptr<pure_type> ptr_type;
        typedef std::set< ptr_type > container_type;

        pure( ptr_type const& parent = nullptr )
		 : m_engine( nullptr )
		 , m_parent( parent  )
	     , m_canvas( nullptr )
		 {
		 }
      //pure( pure const& original ){ *this = P_original; }
       ~pure(){ }
      //pure & operator=( pure const& original ){ return *this; }

      public:
        engine_type    const& engine()const{ return *m_engine; }
        engine_type         & engine()     { return *m_engine; }
	 protected:
		 engine_ptr_type     & engine_ptr() { return m_engine; }
      private:
        engine_ptr_type m_engine;

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
      protected:
        canvas_ptr_type     & canvas_ptr()     { return m_canvas; }
      private:
        canvas_ptr_type m_canvas;

     };

   }
 }

#endif

