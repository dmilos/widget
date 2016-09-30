#ifndef widget_event_consumer_function
#define widget_event_consumer_function

//widget::event::consumer::function

#include "../id.hpp"
#include "./pure.hpp"

namespace widget
 {
  namespace event
   {
    namespace consumer
     {

      class function
       : public ::widget::event::consumer::pure
       {
        public:
          typedef ::widget::event::pure            event_type;
          typedef ::widget::event::action_type     action_type;

        public:
          explicit  function( action_type const& action_param ):m_action( action_param ){ }
          virtual  ~function(){ }

        public:
          action_type    const& action()const{ return m_action; }
          virtual void action( action_type const& action_param )
           {
            m_action = action_param;
           }

        protected:
          action_type        & action(){ return m_action; }
        private:
          action_type m_action;

        public:
          bool process( event_type const& event )
           {
            return m_action( event );
           }

       };

   }
  }
 }

#endif
