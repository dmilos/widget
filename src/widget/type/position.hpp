#ifndef widget_type_position
#define widget_type_position

#include <array>



namespace widget
 {
  namespace type
   {

    typedef int integer_type;

    typedef std::array< integer_type, 1> position1d_type;
    typedef std::array< integer_type, 2> position2d_type;
    typedef std::array< integer_type, 3> position3d_type;
    typedef std::array< integer_type, 4> position4d_type;
    typedef std::array< integer_type, 5> position5d_type;

	template< typename number_name, unsigned dimension_number >
	  using positionNd_type = std::array< typename number_name, dimension_number >;

   }
 }

#endif
