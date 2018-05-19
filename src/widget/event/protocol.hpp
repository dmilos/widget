#ifndef widget_event_protocol
#define widget_event_protocol

// widget::event::protocol

#include <map>

#include "./id.hpp"
#include "./action.hpp"
#include "./pure.hpp"

namespace widget
 {
  namespace event
   {
    namespace consumer
     {

      class protocol
       : public ::widget::event::consumer::pure
       {
        public:
          typedef ::widget::event::pure::source_type              source_type;
          typedef ::widget::event::pure::ID_type                      ID_type;
          typedef ::widget::event::pure::pair_type                  pair_type;

          typedef ::widget::event::consumer::action_type    action_type;
    
          typedef std::map< id_type, action_type > container_type;
    
    
        public:
          bool process( event_type const& event )
           {
            auto i = m_container.find(event.id() );
            if( m_container.end() == i )
             {
              return false;
             }
            return i->second( event );
           }
    
        public:
                  void clear(  ){ m_container.clear(); }
          virtual void trigger( pair_type const& pair, action_type const& action )
           {
            m_container.emplace( pair, action );
           }

        public:
          container_type    const& container()const{ return m_container; }
        protected:
          container_type        & container_direct(){ return m_container; }
        private:
          container_type m_container;
       };

     }
   }
 }

#endif
