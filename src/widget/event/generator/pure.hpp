#ifndef widget_event_generator_pure
#define widget_event_generator_pure

// widget::event::generator::pure

#include "../action.hpp"
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
          typedef widget::event::action_type action_type;

        public:
          explicit  pure( ){ }
          virtual  ~pure(){ }

        public:
          void action( action_type const& action_param ){ m_action = action_param; }
        protected:
          action_type & action(){ return m_action; }
        private:
          action_type m_action;

        public:
		  virtual bool run() =0;
          virtual void stop() =0;

       };

   }
  }
 }

#endif
