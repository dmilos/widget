#ifndef widget_canvas_win32
#define widget_canvas_win32

// widget::canvas::win32

#include <windows.h>



#include "./crop.hpp"

namespace widget
 {
  namespace canvas
   {

    class win32
     : public virtual widget::canvas::crop< std::size_t, int, 2 >
     {
      public:
        typedef widget::canvas::crop< std::size_t, int, 2 > crop_type;

        typedef crop_type::sizeNd_type sizeNd_type, size2d_type;

        win32();
      //pure( pure const& original ){ *this = P_original; }
       ~win32();
      //pure & operator=( pure const& original ){ return *this; }

       void clear();

      public:
        using crop_type::size;
        bool          size( sizeNd_type const& size_param );

      public:
        HWND    m_hWnd;
        void hWnd( HWND const& hwnd );

      public:
        HDC     m_dc;
        HBITMAP m_bitmap;
        HGDIOBJ m_hOld;
     };

   }
 }

#endif
