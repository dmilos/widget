#ifndef widget_element_basic
#define widget_element_basic

// widget::element::basic

#include <memory>
#include "./pure.hpp"
#include "../../event/consumer/devnull.hpp"


namespace widget
 {
  namespace window
   {
    namespace element
     {

      class basic
       : public  ::widget::window::element::pure<std::size_t, int, 2>
       {
        public:
          typedef ::widget::window::element::pure<std::size_t, int, 2>  pure_type;
      
          typedef ::widget::type::dumb_ptr< pure_type::primitive_type > primitive_ptr_type;
          typedef std::unique_ptr< pure_type::consumer_type  >  consumer_ptr_type;
      
          basic();
          basic(primitive_ptr_type const& primitive_param, consumer_ptr_type & consumer_param = consumer_ptr_type{ new ::widget::event::consumer::devnull });
        //pure( pure const& original ){ *this = P_original; }
         ~basic();
        //pure & operator=( pure const& original ){ return *this; }
      
        public:
          void draw( canvas_type & canvas_param )const;
          bool process( event_type const & event_param );
      
        public:
          consumer_type    const& consumer()const { return *m_consumer; }
          consumer_type         & consumer() { return *m_consumer; }
          void                  consumer( consumer_ptr_type & cp )
           {
            m_consumer = std::move( cp );
           }
        protected:
          consumer_ptr_type     & consumer_ptr() { return m_consumer; }
        private:
          consumer_ptr_type m_consumer;
      
        public:
          primitive_type    const& primitive()const { return *m_primitive; }
          primitive_type         & primitive() { return *m_primitive; }
        protected:
          primitive_ptr_type     & primitive_ptr() { return m_primitive; }
        private:
          primitive_ptr_type m_primitive;
       };

     }
   }
 }

#endif

