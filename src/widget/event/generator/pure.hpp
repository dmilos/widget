#ifndef widget_event_generator_pure
#define widget_event_generator_pure

// widget::event::generator::pure

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
          typedef ::widget::event::pure event_type;
          typedef ::widget::element::pure element_type;
		  typedef ::widget::type::dumb_ptr<element_type> element_ptr_type;

        public:
          explicit  pure( ){ }
          virtual  ~pure(){ }

        public:
          virtual void element( element_ptr_type element_param){ m_element = element_param; }
        protected:
		 element_ptr_type & element_ptr(){ return m_element; }
        private:
			element_ptr_type m_element;

        public:
		  virtual bool run() =0;
          virtual void stop() =0;

       };

   }
  }
 }

#endif
