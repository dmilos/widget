#ifndef widget_event_consumer_simple
#define widget_event_consumer_simple

// ::widget::event::consumer::simple

#include "../id.hpp"
#include "./pure.hpp"

namespace widget
 {
  namespace event
   {
    namespace consumer
     {

      class simple
       : public ::widget::event::consumer::pure
       {
        public:
          typedef ::widget::event::pure            event_type;

          typedef ::widget::event::consumer::protocol           function_type;
          typedef ::widget::event::consumer::protocol           protocol_type;

        public:
          explicit  simple( ){ }
          virtual  ~simple(){ }

        public:
            void trigger( event_type const& event, function_type const& job )
             {
              m_protocol.trigger( event, job );
             }

        public:
          protocol_type m_protocol;

        public:
          bool process( event_type const& event )
           {
            return true;
           }

       };

   }
  }
 }

#endif
