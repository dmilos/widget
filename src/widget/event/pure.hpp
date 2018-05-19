#ifndef widget_event_pure
#define widget_event_pure

#include <cstdint>
#include <array>

// ::widget::event::pure

#include "./id.hpp"

namespace widget
 {
  namespace event
   {

    class pure
     {
      public:
        typedef widget::event::id_type     source_type;
        typedef widget::event::id_type         ID_type;

        typedef std::pair< source_type, ID_type >     pair_type;

        typedef std::array<std::uint8_t,128> data_type;

      public:
        explicit  pure( source_type const& source_param, ID_type const& id_param, data_type const& data = data_type() )
         :m_source(source_param)
         ,m_id(id_param)
       //,m_data(data_param)
          {
          }

         ~pure(){ }

      public:
         source_type    const& source()const { return m_source; }
      private:
        source_type  m_source;

      public:
        ID_type    const& id()const{ return m_id; }
      protected:
        ID_type        & id(){ return m_id; }
      private:
        ID_type m_id;

      public:
        data_type    const& data()const { return m_data; }
        data_type         &  data()     { return m_data; }
      protected:
        data_type    m_data;
     };

   }
 }

#endif
