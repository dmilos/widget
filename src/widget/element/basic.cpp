#include "./basic.hpp"

#include "../canvas/native.hpp"
#include "../event/engine/simple.hpp"


::widget::element::basic::basic()
 {
  engine_ptr() = new ::widget::event::engine::simple;
  canvas_ptr() = new ::widget::canvas::native;
 }

::widget::element::basic::~basic()
 {

 }


