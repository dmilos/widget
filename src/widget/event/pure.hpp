#ifndef widget_event_pure
#define widget_event_pure

#include "./id.hpp"

namespace widget
 {
  namespace event
   {

    class pure
     {
      public:
        typedef widget::event::id_type id_type;

      public:
        explicit  pure( id_type const& id_param = 0 ):m_id(id_param){ }
        virtual  ~pure(){ }
      public:
                  id_type    const& id()const{ return m_id; }
      protected:
          id_type        & id(){ return m_id; }
      private:
          id_type m_id;

     };

   }
}

#endif
