#ifndef widget_event_consumer_pure
#define widget_event_consumer_pure

#include "../pure.hpp"

namespace widget
 {
  namespace event
   {
    namespace consumer
     {

      class pure
       {
        public:
          typedef ::widget::event::pure            event_type;

        public:
                    pure( ){ }
          virtual  ~pure(){ }

        public:
          virtual bool process( event_type const& event )=0;

       };

   }
  }
 }

#endif
