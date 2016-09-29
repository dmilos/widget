#include <iostream>
#include <iomanip>

#include "widget/element/basic.hpp"
#include "widget/primitive/background.hpp"
#include "widget/primitive/text.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  widget::element::basic w;

  w.canvas().draw( ::widget::primitive::background( {0,0,0} ) )
            .draw( ::widget::primitive::text( { 0, 0 }, "Hello World" ) );

  cin.get();

  return EXIT_SUCCESS;
 }

