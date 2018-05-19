#ifndef widget_event_consumer_devnull
#define widget_event_consumer_devnull

// ::widget::event::consumer::devnull

#include "../id.hpp"
#include "./pure.hpp"

namespace widget
 {
  namespace event
   {
    namespace consumer
     {

      class devnull
       : public ::widget::event::consumer::pure
       {
        public:
          typedef ::widget::event::pure            event_type;

        public:
          explicit  devnull( ){ }
          virtual  ~devnull(){ }

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
