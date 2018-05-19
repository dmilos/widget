#ifndef widget_window_win32
#define widget_window_win32

// widget::window::basic< size_name, position_name, dimension_number >


#include "./basic.hpp"
#include "../canvas/native.hpp"
#include "../event/generator/native.hpp"
#include "./exchange/process.hpp"

namespace widget
 {
  namespace window
   {

    template< typename size_name, typename position_name, unsigned dimension_number >
     class win32
      : public ::widget::window::basic< size_name, position_name, dimension_number>
      , ::widget::canvas::win32
      , ::widget::event::generator::win32
      {
       public:

         typedef ::widget::window::basic< size_name, position_name, dimension_number> basic_type;

         typedef ::widget::canvas::win32 canvas_type;
         typedef ::widget::event::generator::win32 generator_type;

         typedef ::widget::event::pure                  event_type;

         win32(  )
          {
           this->basic_type::generator(  this );
           this->basic_type::canvas(     this );
           this->basic_type::consumer( this );
           this->basic_type::generator()->consumer( this );
          }

         virtual ~win32() { }

         bool run()override
          {
           if( true == this->generator_type::active() )
            {
             return true;
            }

           if( false == this->generator_type::run() )
            {
             return false;
            }

           if( false == ::widget::window::exchange::process( *this, *this ) )
            {
             return false;
            }

           return true;
          }

         void stop(){ this->generator_type::stop(); }

         bool process( event_type const & e )
          {
           switch( e.id() )
            {
             case( 0x000F ):
               {
                PAINTSTRUCT ps;

                HDC hdc = BeginPaint( this->canvas_type::m_hWnd, &ps );

                BitBlt( hdc, 0, 0, this->size()[0], this->size()[1], this->m_dc, 0, 0, SRCCOPY );

                for( auto const& element: this->element_container() )
                 {
                  element.second->draw( * this->canvas_protected() );
                 }

               if(false){
                COLORREF clrRed  = RGB(  255,   25,  5 );
                COLORREF clrAqua = RGB(    0, 255, 255 );
                COLORREF clrNavy = RGB(    0,   0, 128 );

                SetBkColor(hdc, RGB(255, 255, 255));    SetTextColor(hdc, clrRed);    TextOut( hdc, 10, 10, "Johnny Carson", 13);
                SetBkColor(hdc, clrNavy);               SetTextColor(hdc, clrAqua);   TextOut( hdc, 150, 180, "The once king of late-night", 27);
               }

               EndPaint( this->canvas_type::m_hWnd, &ps );
              }return true;
             case( 0x0005 ):
              {
               std::size_t width  =  (std::size_t(e.data()[1])  << 8) +  e.data()[0];
               std::size_t height =  (std::size_t(e.data()[3])  << 8) +  e.data()[2];

               this->size( { width, height } );
              } return true;
            }
           return false;
          }

      };

    }
}

#endif
