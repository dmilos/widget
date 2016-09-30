
#include "./win32.hpp"

widget::event::generator::win32::win32()
 {
 }

widget::event::generator::win32::~win32()
 {
 }

widget::event::generator::pure::event_type const&
widget::event::generator::win32::generate()
 {
  return widget::event::pure{};
 }