#ifndef widget_event_protocol
#define widget_event_protocol

#include <map>

#include "./id.hpp"
#include "./action.hpp"

namespace widget
 {
  namespace event
   {

    class protocol
     {
      public:
        typedef ::widget::event::id_type         id_type;
        typedef ::widget::event::action_type    action_type;

        typedef std::map< id_type, action_type > container_type;

      public:
                void clear(  ){ m_container.clear(); }
        virtual void insert( id_type const& id, action_type const& action )
         {
          m_container.emplace( id, action );
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

#endif
