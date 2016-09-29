#ifndef widget_event_generator_pure
#define widget_event_generator_pure

#include "../../type/dumb.hpp"
#include "../../element/pure.hpp"
#include "../pure.hpp"

namespace widget
 {
  namespace event
   {
    namespace generator
     {

      class pure
       {
        public:
          typedef widget::event::pure event_type;
          typedef widget::element::pure element_type;
          typedef widget::type::dumb_ptr<element_type> element_ptr_type;

          typedef element_type element_type;

        public:
          explicit  pure( ){ }
          virtual  ~pure(){ }

        public:
          void element( element_ptr_type const& element_param ){ m_element = element_param; }
        protected:
          element_ptr_type & element(){ return m_element; }
        private:
          element_ptr_type m_element;

        public:
          bool run();
          void stop();

        protected:
          virtual event_type const& generate()=0;

       };

   }
  }
 }

#endif
