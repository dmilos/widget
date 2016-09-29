#ifndef widget_event_engine_simple
#define widget_event_engine_simple

#include "./id.hpp"

namespace widget
 {
  namespace event
   {
    namespace engine
     {

      class simple
       {
        public:
          typedef widget::event::pure            event_type;
          typedef widget::event::protocol     protocol_type;
          typedef ::widget::event::id_type          id_type;

        public:
                    simple( ){ }
          virtual  ~simple(){ }

        public:
          protocol_type    const& protocol()const{ return m_protocol; }
          virtual void protocol( id_type const& id, action_type const& action );
           {
            //std::guard_lock<> locker( m_mutex );
            m_protocol.insert( id, action );
           }

        protected:
          protocol_type        & protocol(){ return m_size; }
        private:
          protocol_type m_protocol;

        public:
          bool process( event_type const& event )
           {
            auto iterator = protocol.container().find( event.id() );

            if( protocol.container().end() == iterator )
             {
              return false;
             }

            return iterator->second( event );
           }

       };

   }
  }
 }

#endif
