# Yet another c++ library that implements color.
###Status:
- Highly experimental

###Description
 - Yet another c++ GUI library

###Key features:
- Small

###Code sample:
```c++
#include <iostream>
#include <iomanip>
#include "widget/widget.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  widget::element::basic w;

  w.canvas( widget::primitive::text( { 0, 0 }, "Hello World" ) );

  return EXIT_SUCCESS;
 }
```

###Install:
1. Clone this Repository:  
