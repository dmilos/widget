#ifndef widget_window_pure
#define widget_window_pure

// widget::element::pure

#include <set>
#include <map>

#include "../type/id.hpp"

#include "../canvas/pure.hpp"
#include "../event/generator/pure.hpp"
#include "./element/pure.hpp"


namespace widget
 {
  namespace window
   {

    template< typename size_name, typename position_name, unsigned dimension_number >
     class pure
      : public virtual ::widget::canvas::pure< size_name, position_name, dimension_number>
      , public virtual ::widget::event::consumer::pure
      {
       public:
         typedef ::widget::canvas::pure< size_name, position_name, dimension_number >     canvas_type;
         typedef ::widget::event::consumer::pure                                        consumer_type;

         typedef ::widget::window::element::pure< size_name, position_name, dimension_number >   element_type;

         typedef ::widget::type::id_type id_type;

         typedef ::widget::type::dumb_ptr< element_type  >  element_ptr_type;
         typedef std::map< id_type, element_ptr_type >  element_container_type;

         pure( )
          {
          }

         //pure( pure const& original ){ *this = P_original; }
         virtual ~pure() { }
         //pure & operator=( pure const& original ){ return *this; }

         virtual bool attach( element_ptr_type const& element_param ) 
          {
           if( true == m_element.empty() ) 
            {
             return this->attach( id_type(0), element_param);
            }
           return this->attach( m_element.rbegin()->first + 1, element_param);
          }

         virtual bool attach(id_type const ID, element_ptr_type const& element_param)
          {
           this->m_element[ ID ] =  element_param;
           return true;
          }

         virtual void remove( id_type const ID )
          {
           this->m_element.erase( ID );
          }

       public:
         element_container_type    const& element_container()const{ return m_element; }
       protected:
         element_container_type        & element_container(){ return m_element; }
       private:
         element_container_type m_element;

      };

   }
 }

#endif
