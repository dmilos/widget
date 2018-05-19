#include "./basic.hpp"

#include "../../canvas/native.hpp"
#include "../../canvas/primitive/nothing.hpp"

::widget::window::element::basic::basic()
 {
  primitive_ptr() = new ::widget::canvas::primitive::nothing<std::size_t, int, 2>;
  consumer_ptr() = consumer_ptr_type{ new ::widget::event::consumer::devnull };
 }

::widget::window::element::basic::basic( primitive_ptr_type const& primitive_param, consumer_ptr_type & consumer_param )
 {
  primitive_ptr() = primitive_param;
  consumer_ptr() = std::move( consumer_param );
 }

::widget::window::element::basic::~basic()
 {
 }

void ::widget::window::element::basic::draw( canvas_type & canvas_param )const
 {
  m_primitive->draw( canvas_param );
 }

bool ::widget::window::element::basic::process( event_type const & event_param )
 {
  return m_consumer->process( event_param );
 }
