#include <iostream>
#include <iomanip>

#include "widget/element/basic.hpp"
#include "widget/primitive/text.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  widget::element::basic w;

  w.canvas().draw( widget::primitive::background(  ::color::constant::solver_type{} ) )
            .draw( widget::primitive::text( { 0, 0 }, "Hello World" ) );

  return EXIT_SUCCESS;
 }

