#include "./process.hpp"

#include "./win32.hpp"

bool widget::window::exchange::prepare::win32( widget::canvas::win32 & c, widget::event::generator::win32 & g )
 {
 // TODOs
  g.m_size = c.size() ;
  return true;
 }

bool widget::window::exchange::report::win32( widget::canvas::win32 & c, widget::event::generator::win32 & g )
 {
  c.hWnd( g.hWnd() );
  return true;
 }
