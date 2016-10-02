#ifndef widget_primitive_text
#define widget_primitive_text

// widget::primitive::text

#include "../type/color.hpp"
#include "../type/position.hpp"
#include "../type/string.hpp"
#include "./pure.hpp"


#include "./pure.hpp"

namespace widget
 {
  namespace primitive
   {

    class text
     : public ::widget::primitive::pure
     {
      public:
        typedef ::widget::type::color_type  color_type;
        typedef ::widget::type::position2d_type position2d_type;
        typedef ::widget::type::string_type string_type;



      public:
                 text( position2d_type const& position, string_type const& content, color_type const& color = color_type{} )
                  :m_position( position )
                  ,m_content( content )
                  ,m_color( color )
                  {
                  }
      public:
        void draw( canvas_type & canvas_param )const;
      public:
        string_type     m_content;
        position2d_type m_position;
        color_type      m_color;
     };

   }
 }

#endif
