#include "./box.hpp"


#if defined( _MSC_VER )
#include "../canvas/win32.hpp"
#endif

#if defined( __GNUC__ )
#include "../canvas/xlib.hpp"
#endif


void
widget::primitive::box::draw( canvas_type & canvas_param )const
 {
 }
