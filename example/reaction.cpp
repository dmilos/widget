#include <iostream>
#include <iomanip>

#include "widget/element/basic.hpp"
#include "widget/primitive/background.hpp"
#include "widget/primitive/text.hpp"
#include "widget/primitive/flush.hpp"
#include "widget/primitive/pixel.hpp"
#include "widget/primitive/circle.hpp"
#include "widget/event/constant/mouse.hpp"

#include "widget/event/generator/native.hpp"

#include "widget/canvas/native.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  widget::event::generator::native g;

  widget::element::basic w;
  widget::element::basic b1;

  w.canvas().size( { 400, 400 } );
  w.draw( ::widget::primitive::background( { 10, 0, 150 } ) )
   .draw( ::widget::primitive::text( { 0,  0 }, "Hello Woooorld", { 0, 0, 255 } ) )
   .draw( ::widget::primitive::text( { 0, 20 }, "Hell",           { 255,0,0 } ) )
   .draw( ::widget::primitive::text( { 0, 40 }, "Hell 5",         { 0,255,0 } ) )
   .draw( ::widget::primitive::pixel( { 0, 0 }, {255,0,0 } ) )
   .draw( ::widget::primitive::circle( { 100, 100 }, 50, { 255,255,255 } ) )
   .draw( ::widget::primitive::flush( ) );

  w.consumer().protocol( (::widget::event::id_type)::widget::event::constant::mouse::button_00_down, []( ::widget::event::pure const& )->bool{ return true; } );

  w.attach( &b1 );

  g.element( &w );
  g.run();

  cin.get();

  return EXIT_SUCCESS;
 }

