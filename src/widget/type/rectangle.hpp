#ifndef widget_type_rectangle
#define widget_type_rectangle

#include <array>

#include "./position.hpp"


namespace widget
 {
  namespace type
   {

    template< typename number_name, unsigned dimension_number > 
     using rectangleNd_type = std::pair
                                    <
                                       ::widget::type::positionNd_type<number_name, dimension_number >
                                     , ::widget::type::positionNd_type<number_name, dimension_number > 
                                    >;


    template< typename number_name > 
      using rectangle1d_type = ::widget::type::rectangleNd_type<number_name, 1 >;
    template< typename number_name > 
      using rectangle2d_type = ::widget::type::rectangleNd_type<number_name, 2 >;
    template< typename number_name > 
      using rectangle3d_type = ::widget::type::rectangleNd_type<number_name, 3 >;
    template< typename number_name > 
      using rectangle4d_type = ::widget::type::rectangleNd_type<number_name, 4 >;
    template< typename number_name > 
      using rectangle5d_type = ::widget::type::rectangleNd_type<number_name, 5 >;
   }
 }

#endif
