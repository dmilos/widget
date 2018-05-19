#include "./process.hpp"

#include "./win32.hpp"

bool widget::window::exchane::win32( widget::canvas::win32 & c, widget::event::generator::win32 & g )
 {
  c.hWnd( g.m_hWnd );
  return true;
 }
