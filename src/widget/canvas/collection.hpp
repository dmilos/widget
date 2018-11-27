#ifndef widget_canvas_collection
#define widget_canvas_collection

// widget::canvas::collection< size_name, position_name, dimension_number >

#include <vector>



namespace widget
 {
  namespace canvas
   {

    template< typename size_name, typename position_name, unsigned dimension_number >
     class collection
      : virtual public widget::canvas::pure<size_name, position_name, dimension_number>
      {
       public:
         typedef size_name           size_type;
         typedef position_name   position_type;

         typedef ::std::size_t   key_type;

         typedef widget::canvas::primitive::pure< size_name, position_name, dimension_number > primitive_type;

         typedef ::widget::type::dumb_ptr< primitive_type > primitive_pointer_type;

         typedef std::vector< primitive_pointer_type > container_type;

         collection(){ }
        virtual ~collection(){ }

       public:
        virtual void refresh()
         {
          protector_type p(*this);
          for( auto const& p : this->m_container )
           {
            p->draw( * this );
           }
         }

       public:
         virtual key_type attach( primitive_pointer_type const& primitive_param )
          {
           protector_type p(*this);
           if( true == this->m_container.empty() )
            {
             return this->attach( key_type(0), primitive_param);
            }
           return this->attach( this->m_container.size() + 1, primitive_param);
          }

       public:
         virtual key_type attach( key_type const key_param, primitive_pointer_type const& primitive_param)
          {
           protector_type p(*this);
           this->m_container.resize( std::max<key_type>( key_param+1, this->m_container.size() ) );
           this->m_container[ key_param ] =  primitive_param;
           return key_param;
          }

       public:
         virtual void remove( key_type const key_param )
          {
           protector_type p(*this);
           // TODO this->m_container.erase( key_param );
          }

       public:
         container_type    const& container()const{ return this->m_container; }
       protected:
         container_type        & container(){ return this->m_container; }
       private:
         container_type m_container;
      };

   }
 }

#endif



