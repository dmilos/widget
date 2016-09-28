
#include "../event/pure.hpp"
#include "../event/action.hpp"
#include "../event/id.hpp"
#include "../type/point.hpp"
#include "../type/.hpp"

// using namespace widget::element::pure
namespace widget
 {
  namespace element
   {

    class pure
     {
      public:
        typedef coord_type;
        typedef size_type;

        typedef widget::element::id       eventID_type;
        typedef widget::element::action  eventAction_type;

        typedef ::widget::element::pure  pure_type;
        typedef  ::pointer::dumb_ptr<pure_type> ptr_type;

        typedef std::map< eventID_type, eventAction_type > protocol_type;
        typedef std::set< ptr_type > container_type;

        pure(){ }
      //pure( pure const& original ){ *this = P_original; }
       ~pure(){ }
      //pure & operator=( pure const& original ){ return *this; }

      public:
        size_type    const& size()const{ return m_size; }
        virtual bool         size(  size_type const& p_size ){ m_size = p_size; return bool( true ); }
      protected:
        size_type        & size(){ return m_size; }
      private:
        size_type m_size;

      public:
        coord_type    const& position()const{ return m_position; }
        virtual bool         position(  coord_type const& p_position ){ m_position = p_position; return bool( true ); }
      protected:
        coord_type        & position(){ return m_position; }
      private:
        coord_type m_position;

      public:
        protocol_type    const& protocol()const{ return m_protocol_type; }
        /*virtual*/ void protocol( eventID_type const& id, eventAction_type const& action );
      protected:
        protocol_type        & protocol(){ return m_protocol_type; }
      private:
        protocol_type m_position;

      public:
        ptr_type    const& parent()const{ return m_parent; }
        virtual bool       parent(  ptr_type const& p_parent ){ m_parent = p_parent ; return bool( true ); }
      protected:
        ptr_type        & parent(){ return m_parent; }
      private:
        ptr_type m_parent;

      public:
        container_type    const& child()const{ return m_child; }
        virtual bool       parent(  ptr_type const& p_child ){ m_child.insert( p_child ); return bool( true ); }
      protected:
        container_type        & child(){ return m_child; }
      private:
        container_type m_child;

     };

   }
 }

