#ifndef widget_type_size
#define widget_type_size

#include <array>



namespace widget
 {
  namespace type
   {

    typedef unsigned size_type;

    typedef std::array< size_type, 1 > size1d_type;
    typedef std::array< size_type, 2 > size2d_type;
    typedef std::array< size_type, 3 > size3d_type;
    typedef std::array <size_type, 4 > size4d_type;
    typedef std::array <size_type, 5 > size5d_type;

    template< typename number_name, unsigned dimension_number > 
     using sizeNd_type = std::array< number_name, dimension_number >;

   }
 }

#endif
