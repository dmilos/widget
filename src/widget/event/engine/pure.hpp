#ifndef widget_event_engine_pure
#define widget_event_engine_pure

#include "../pure.hpp"
#include "../protocol.hpp"

namespace widget
 {
  namespace event
   {
    namespace engine
     {

      class pure
       {
        public:
          typedef ::widget::event::id_type          id_type;
          typedef ::widget::event::protocol     protocol_type;
          typedef ::widget::event::pure            event_type;

        public:
                    pure( ){ }
          virtual  ~pure(){ }

        public:
          protocol_type    const& protocol()const{ return m_protocol; }
          virtual void protocol( id_type const& id, action_type const& action )
           {
            //std::guard_lock<> locker( m_mutex );
            m_protocol.insert( id, action );
           }

        protected:
          protocol_type        & protocol(){ return m_protocol; }
        private:
          protocol_type m_protocol;

        public:
          virtual bool process( event_type const& event )=0;

       };

   }
  }
 }

#endif
