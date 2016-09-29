#include <iostream>
#include <iomanip>

#include "widget/element/basic.hpp"
#include "widget/primitive/background.hpp"
#include "widget/primitive/text.hpp"
#include "widget/event/constant/mouse.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  widget::element::basic w;
  widget::element::basic b1;

  w.canvas().draw( ::widget::primitive::background( {0,0,0} ) )
            .draw( ::widget::primitive::text( { 0, 0 }, "Hello World" ) );

  w.engine().protocol( (::widget::event::id_type)::widget::event::constant::mouse::button_00_down, []( ::widget::event::pure const& )->bool{ return true; } );

  w.attach( &b1 );

  cin.get();

  return EXIT_SUCCESS;
 }

