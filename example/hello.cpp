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
  typedef ::widget::canvas::primitive::text<std::size_t, int, 2>       text_t;
  typedef ::widget::canvas::primitive::background<std::size_t, int, 2> background_t;
  typedef ::widget::canvas::primitive::flush<std::size_t, int, 2>      flush_t;

  typedef ::widget::canvas::primitive::circle<std::size_t, int, 2> circle_t;

  typedef ::widget::canvas::primitive::refresh<std::size_t, int, 2> refresh_t;


  typedef ::widget::window::basic< std::size_t, int, 2 > window_t;

  window_t w; 
  ::widget::window::win32( w );

  w.size( {600,600} );

  ::widget::window::element::basic bg( new background_t{ { 0u, 255u, 0u } } );
  ::widget::window::element::basic tx{ new text_t{ {140u,140u}, "TTTT", { 255, 255, 255 } } };
  ::widget::window::element::basic f{ new flush_t{} };

  w.run();
  w.size( {900u,900u} );

  //w.attach( &bg );
  //w.attach( &tx );
  //w.attach( &f );

  background_t{ { 255u, 0u, 127u } }.draw( *w.canvas() );
  text_t(       { 20u, 50u }, "XXX Hello World XXXX", { 100, 255, 0 } ).draw( *w.canvas() );
  circle_t(     { 20u, 20u }, 15, { 255u, 0u, 0u } ).draw( *w.canvas() );

  //refresh_t{}.draw( *w.canvas() );

  //w.visibility( 0 );

  cin.get();

  return EXIT_SUCCESS;
 }

