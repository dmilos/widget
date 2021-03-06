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
  typedef ::widget::canvas::primitive::pure<std::size_t, int, 2>       primitive_t;

  typedef ::widget::canvas::primitive::text<std::size_t, int, 2>       text_t;
  typedef ::widget::canvas::primitive::background<std::size_t, int, 2> background_t;
  typedef ::widget::canvas::primitive::flush<std::size_t, int, 2>      flush_t;

  typedef ::widget::canvas::primitive::circle<std::size_t, int, 2> circle_t;

  typedef ::widget::canvas::primitive::refresh<std::size_t, int, 2> refresh_t;


  typedef ::widget::window::basic< std::size_t, int, 2  > window_t;

  window_t w;
  ::widget::window::native( w );

  w.offset( {100,100} );
  w.size( {900,600} );

  ::widget::window::element::basic bg( new background_t{ { 0u, 255u, 0u } } );
                            text_t tx(                   { 20u, 50u }, "Hello World ELEMENT", { 100, 255, 0 } ) ;
  ::widget::window::element::basic f{ new flush_t{} };

  //tx.trigger( ::widget::event::pure(0,0) , ::widget::event::consumer::action_type{} );

  w.run();
  w.size( {600u,400u} );

  //w.attach( "bg", &bg );
   w.attach( 0,  &tx );
  //w.attach( "flush", &f );

  background_t{ { 255u, 0u, 127u } }.draw( w );
  text_t(       { 20u, 50u }, "Hello World print", { 100, 255, 0 } ).draw( w );
  circle_t(     { 20u, 20u }, 15, { 255u, 0u, 0u } ).draw( w );

  refresh_t{}.draw( w );

  //w.visibility( 0 );

  cin.get();

  return EXIT_SUCCESS;
 }

