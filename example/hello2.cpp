#include <iostream>
#include <iomanip>

#include "widget/canvas/native.hpp"
#include "widget/canvas/primitive/background.hpp"
#include "widget/canvas/primitive/text.hpp"
#include "widget/canvas/primitive/flush.hpp"
#include "widget/canvas/primitive/refresh.hpp"
#include "widget/window/element/basic.hpp"

#include "widget/window/native.hpp"
#include "widget/canvas/primitive/circle.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  typedef ::widget::canvas::primitive::text<std::size_t, int, 2> text_t;
  typedef ::widget::canvas::primitive::refresh<std::size_t, int, 2> refresh_t;

  typedef ::widget::window::native window_t;

  window_t w;
  w.size( {300,300});
  w.run();

  text_t( { 20u, 20u }, "Hello World", { 100, 255, 0 } ).draw( w );
  refresh_t{}.draw( w );

  cin.get();

  return EXIT_SUCCESS;
 }

