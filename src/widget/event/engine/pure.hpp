#ifndef widget_event_engine_pure
#define widget_event_engine_pure

#include "./id.hpp"

namespace widget
 {
  namespace event
   {
    namespace engine
     {

      class pure
       {
        public:
          typedef widget::event::pure event_type;

        public:
          explicit  pure( ){ }
          virtual  ~pure(){ }

        public:
          void process( event_type const& event )=0;

       };

   }
  }
 }

#endif
