#include "./process.hpp"

#if defined( _MSC_VER )
#include "./win32.hpp"
#endif

#if defined( __GNUC__ )
#include "./xlib.hpp"
#endif
