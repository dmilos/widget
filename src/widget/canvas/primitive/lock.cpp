#include <memory>

#include "./lock.hpp"

void
widget::primitive::lock< std::size_t, int, 2>::draw( canvas_type & canvas_param )const
 {
  canvas_param.lock();
 }
