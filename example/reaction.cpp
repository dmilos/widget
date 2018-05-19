#include <iostream>
#include <iomanip>

#include "widget/element/basic.hpp"
#include "widget/canvas/primitive/background.hpp"
#include "widget/canvas/primitive/text.hpp"
#include "widget/canvas/primitive/flush.hpp"
#include "widget/canvas/primitive/pixel.hpp"
#include "widget/canvas/primitive/circle.hpp"
#include "widget/canvas/primitive/box.hpp"
#include "widget/event/constant/mouse.hpp"

#include "widget/event/generator/native.hpp"
#include "widget/event/consumer/function.hpp"

#include "widget/canvas/native.hpp"

#include "widget/window/basic.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  widget::element::basic button/*( new ::widget::primitive::box<std::size_t,int,2>() )*/;
  widget::element::basic bg(     new ::widget::canvas::primitive::background<std::size_t, int, 2>{ { 255u, 0u, 0u } } )  ;
  widget::element::basic text{   new ::widget::canvas::primitive::text<std::size_t,int,2>{ {10u,10u}, "TTTT", { 255, 255, 255 } } };
  widget::element::basic circle{ new ::widget::canvas::primitive::circle<std::size_t, int, 2>{ { 300u,300u }, 20, { 255, 255, 255 } } };
  widget::element::basic flush{  new ::widget::primitive::flush<std::size_t, int, 2>() };

  ::widget::window::basic<std::size_t, int,2 > w;

  w.attach( &bg );
  w.attach(&text);
  w.attach(&circle);
  w.attach(&flush);

  //circle.consumer().trigger( { widget::event::constant::mouse::_1, widget::event::constant::mouse::button_00_up }, [](::widget::event::pure const&)-> bool { std::cout << "aaaa" << std::endl; });
  //circle.consumer().trigger( { widget::event::constant::keyboard::_1, widget::event::constant::keyboard::A_up },   [](::widget::event::pure const&)-> bool { std::cout << "bbb" << std::endl; });

   w.run();

  cin.get();
  return EXIT_SUCCESS;
 }

