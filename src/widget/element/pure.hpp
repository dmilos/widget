#ifndef widget_element_pure
#define widget_element_pure

#include <map>
#include <set>

#include "../type/size.hpp"

#include "../event/pure.hpp"
#include "../event/action.hpp"
#include "../type/id.hpp"
#include "../type/position.hpp"
#include "../type/dumb.hpp"

// using namespace widget::element::pure
namespace widget
 {
  namespace element
   {

    class pure
     {
      public:
        typedef ::widget::type::position2d_type position2d_type;

        typedef ::widget::type::size2d_type size2d_type;

        typedef ::widget::type::id_type         eventID_type;

        typedef ::widget::element::pure  pure_type;
        typedef ::widget::type::dumb_ptr<pure_type> ptr_type;

        typedef ::widget::event::action_type  eventAction_type;


        typedef std::map< eventID_type, eventAction_type > protocol_type;
        typedef std::set< ptr_type > container_type;

        pure(){ }
      //pure( pure const& original ){ *this = P_original; }
       ~pure(){ }
      //pure & operator=( pure const& original ){ return *this; }

      public:
        size2d_type    const& size()const{ return m_size; }
        virtual bool          size(  size2d_type const& p_size ){ m_size = p_size; return bool( true ); }
      protected:
        size2d_type        & size(){ return m_size; }
      private:
        size2d_type m_size;

      public:
        position2d_type    const& position()const{ return m_position; }
        virtual bool         position(  position2d_type const& p_position ){ m_position = p_position; return bool( true ); }
      protected:
        position2d_type        & position(){ return m_position; }
      private:
        position2d_type m_position;

      public:
        protocol_type    const& protocol()const{ return m_protocol; }
        /*virtual*/ void protocol( eventID_type const& id, eventAction_type const& action );
      protected:
        protocol_type        & protocol(){ return m_protocol; }
      private:
        protocol_type m_protocol;

      public:
        ptr_type    const& parent()const{ return m_parent; }
        virtual bool       parent(  ptr_type const& p_parent ){ m_parent = p_parent ; return bool( true ); }
      protected:
        ptr_type        & parent(){ return m_parent; }
      private:
        ptr_type m_parent;

      public:
        container_type    const& child()const{ return m_child; }
      protected:
        container_type        & child(){ return m_child; }
      private:
        container_type m_child;

     };

   }
 }

#endif

