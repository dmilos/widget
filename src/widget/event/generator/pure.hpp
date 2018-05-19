#ifndef widget_event_generator_pure
#define widget_event_generator_pure

// widget::event::generator::pure

#include <atomic>

#include "../consumer/pure.hpp"
#include "../consumer/devnull.hpp"
#include "../pure.hpp"
#include "../../type/dumb.hpp"

namespace widget
 {
  namespace event
   {
    namespace generator
     {

      class pure
       { 
        public:
          typedef ::widget::event::pure                          event_type;
          typedef ::widget::event::consumer::pure             consumer_type;
          typedef ::widget::type::dumb_ptr<consumer_type> consumer_ptr_type;

          typedef std::atomic<bool>  active_type;

        public:
                    pure():m_active(false), m_consumer( new ::widget::event::consumer::devnull ){ }
          virtual  ~pure(){ }

        public:
          consumer_ptr_type const& consumer(  )const{ return m_consumer; }
          virtual void             consumer( consumer_ptr_type consumer_param ){ m_consumer = consumer_param; }
        protected:
          consumer_ptr_type & consumer_protected(){ return m_consumer; }
        private:
          consumer_ptr_type m_consumer;

        public:
          active_type const& active()const{ return m_active; }
        protected:
          active_type & active_protected(){ return m_active; }
        private:
          active_type m_active;

        public:
          virtual bool run() =0;
          virtual void stop() =0;
       };

   }
  }
 }

#endif
