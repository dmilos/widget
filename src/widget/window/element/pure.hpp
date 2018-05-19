#ifndef widget_element_pure
#define widget_element_pure

// widget::element::pure< size_name, position_name, dimension_number >

#include <set>
#include <memory>

#include "../../type/size.hpp"
#include "../../type/dumb.hpp"

#include "../../event/consumer/pure.hpp"
#include "../../canvas/pure.hpp"
#include "../../canvas/primitive/pure.hpp"


namespace widget
 {
  namespace window
   {
    namespace element
     {

      template< typename size_name, typename position_name, unsigned dimension_number >
       class pure
        : public ::widget::canvas::primitive::pure< size_name, position_name, dimension_number>
        , public ::widget::event::consumer::pure
        {
         public:
           typedef ::widget::canvas::pure< size_name, position_name, dimension_number >  canvas_type;
           typedef ::widget::canvas::primitive::pure< size_name, position_name, dimension_number >  primitive_type;
      
           typedef ::widget::event::consumer::pure              consumer_type;
           typedef ::widget::event::consumer::pure::event_type     event_type;
      
           typedef ::widget::window::element::pure< size_name, position_name, dimension_number >  pure_type;
           typedef ::widget::type::dumb_ptr<pure_type> dumb_ptr_type;
           typedef std::unique_ptr<pure_type> unique_ptr_type;
      
           typedef std::set< unique_ptr_type > container_type;
      
           pure( dumb_ptr_type const& parent = nullptr )
            : m_parent( parent )
            {
            }
      
         //pure( pure const& original ){ *this = P_original; }
          ~pure(){ }
         //pure & operator=( pure const& original ){ return *this; }
      
         public:
           dumb_ptr_type    const& parent()const{ return m_parent; }
           virtual bool       parent(  dumb_ptr_type const& p_parent )
            {
             m_parent = p_parent;
             return bool( true ); 
            }
         protected:
           dumb_ptr_type        & parent(){ return m_parent; }
         private:
           dumb_ptr_type m_parent;
       
         public:
           container_type    const& child()const{ return m_child; }
           virtual bool       attach(  unique_ptr_type & child )
            {
             m_child.emplace(std::move( child ) );
             child->parent( this ); 
             return bool( true ); 
            }
         protected:
           container_type        & child(){ return m_child; }
         private:
           container_type m_child;
      
        };

     }
   }
 }

#endif
