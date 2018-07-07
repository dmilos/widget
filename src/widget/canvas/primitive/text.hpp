#ifndef widget_primitive_text
#define widget_primitive_text

// widget::primitive::text

#include "../../type/color.hpp"
#include "../../type/position.hpp"
#include "../../type/string.hpp"
#include "./pure.hpp"


#include "./pure.hpp"

namespace widget
 {
  namespace canvas
   {
    namespace primitive
     {

      template< typename size_name, typename position_name, unsigned dimension_number >
       class text
        : public ::widget::canvas::primitive::pure< size_name, position_name, dimension_number >
        {
         public:
           typedef ::widget::type::string_type         string_type;
      
           typedef ::widget::canvas::primitive::pure<size_name, position_name, dimension_number> pure_type;
           typedef ::widget::type::color_type  color_type;
           typedef ::widget::type::positionNd_type<position_name, dimension_number> positionNd_type;

         public:
                    text( positionNd_type const& position, string_type const& content, color_type const& color = color_type{} )
                     :m_position( position )
                     ,m_content( content )
                     ,m_color( color )
                     {
                     }
         public:
           void draw( canvas_type & canvas_param )const;
         public:
           string_type     m_content;
           positionNd_type m_position;
           color_type      m_color;
        };

     }
   }
 }

#endif
