#ifndef widget_canvas_win32
#define widget_canvas_win32

// widget::canvas::win32

#include <windows.h>



#include "./pure.hpp"

namespace widget
 {
  namespace canvas
   {

    class win32
    : public virtual widget::canvas::pure< std::size_t, int, 2 >
     {
      public:
        typedef widget::canvas::pure< std::size_t, int, 2 > pure_type;

        typedef pure_type::sizeNd_type sizeNd_type, size2d_type;

        win32();
      //pure( pure const& original ){ *this = P_original; }
       ~win32();
      //pure & operator=( pure const& original ){ return *this; }

       void clear();

      public:
        sizeNd_type    const& size()const{ return m_size; }
        virtual bool          size( sizeNd_type const& size_param );
      protected:
        sizeNd_type         & size_protected(){ return m_size; }
      private:
        sizeNd_type m_size;

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
