#include <iostream>
#include <iomanip>

#include "widget/element/basic.hpp"
#include "widget/primitive/background.hpp"
#include "widget/primitive/text.hpp"
#include "widget/event/constant/mouse.hpp"

#include "widget/event/generator/native.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  widget::event::generator::native g;

  widget::element::basic w;
  widget::element::basic b1;

  w.canvas().draw( ::widget::primitive::background( {0,0,0} ) )
            .draw( ::widget::primitive::text( { 0,  0 }, "Hello Woooorld" ) )
            .draw( ::widget::primitive::text( { 0, 20 }, "Hell" ) )
            .draw( ::widget::primitive::text( { 0, 40 }, "Hell 5" ) );

  w.consumer().protocol( (::widget::event::id_type)::widget::event::constant::mouse::button_00_down, []( ::widget::event::pure const& )->bool{ return true; } );

  w.attach( &b1 );

  g.element( &w );
  g.run();

  cin.get();

  return EXIT_SUCCESS;
 }

