#include "./basic.hpp"

#include "../canvas/native.hpp"
#include "../event/consumer/simple.hpp"


::widget::element::basic::basic()
 {
  consumer_ptr() = new ::widget::event::consumer::simple;
  canvas_ptr() = new ::widget::canvas::native;
 }

::widget::element::basic::~basic()
 {

 }


