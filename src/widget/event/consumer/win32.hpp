#ifndef widget_event_consumer_win32
#define widget_event_consumer_win32

// widget::event::consumer::win32


#include "../canvas/win32.hpp"
#include "../event/consumer/pure.hpp"
#include "../window/pure.hpp"





namespace widget
 {
  namespace event
   {
    namespace consumer
     {

      class win32
       : public ::widget::event::consumer::pure
        {
         public:

           typedef widget::type::size_type size_type;
           typedef int integer_type;

           typedef ::widget::event::consumer::pure      pure_type;
           typedef ::widget::canvas::win32            canvas_type;
           typedef ::widget::window::pure< size_type, integer_type, 2 > window_type;
           typedef ::widget::event::pure               event_type;

           typedef ::widget::type::dumb_ptr< canvas_type >   canvas_ptr_type;
           typedef ::widget::type::dumb_ptr< window_type >   window_ptr_type;

           win32()
            {
             m_window = nullptr;
             m_canvas = nullptr;
            }

           virtual ~win32() { }

         public:
           virtual canvas_ptr_type    const& canvas()const{ return m_canvas; }
           virtual void canvas( canvas_ptr_type const& canvas_param )
            {
             m_canvas = canvas_param;
            }
         protected:
           canvas_ptr_type        & canvas_protected(){ return m_canvas; }
         private:
           canvas_ptr_type m_canvas;

         public:
           virtual window_ptr_type    const& window()const{ return m_window; }
           virtual void window( window_ptr_type const& window_param )
            {
             m_window = window_param;
            }
         protected:
           window_ptr_type        & window_protected(){ return m_window; }
         private:
           window_ptr_type m_window;

         protected:
           bool process( event_type const & e )
            {
             switch( e.id() )
              {
               case( 0x000F ):
                 {
                  widget::canvas::win32 * w32c = dynamic_cast<widget::canvas::win32*>( this->canvas_protected() );
                  if( nullptr == w32c )
                   {
                    break;
                   }
                  PAINTSTRUCT ps;
                  HDC hdc = BeginPaint( w32c->m_hWnd, &ps );
                  //w32c->DC( hdc );

                  BitBlt( hdc, 0, 0, int( w32c->size()[0]), int( w32c->size()[1] ), w32c->m_dc, 0, 0, SRCCOPY );

                  typedef widget::canvas::collection<size_type,integer_type,2> collection_t;
                  collection_t * c = dynamic_cast<collection_t*>( &(*this->canvas_protected()) );
                  if( nullptr != c )
                   {
                    c->refresh();
                   }

                 if(false){
                  COLORREF clrRed  = RGB(  255,   25,  5 );
                  COLORREF clrAqua = RGB(    0, 255, 255 );
                  COLORREF clrNavy = RGB(    0,   0, 128 );

                  SetBkColor(hdc, RGB(255, 255, 255));    SetTextColor(hdc, clrRed);    TextOutA( hdc, 10, 10,      "Johnny CARSON" , 13);
                  SetBkColor(hdc, clrNavy);               SetTextColor(hdc, clrAqua);   TextOutA( hdc, 150, 180,   "The once king of late-night" , 27);
                 }

                 EndPaint( w32c->m_hWnd, &ps );
                }return true;
               case( 0x0005 ):
                {
                 std::size_t width  =  (std::size_t(e.data()[1])  << 8) +  e.data()[0];
                 std::size_t height =  (std::size_t(e.data()[3])  << 8) +  e.data()[2];

                 {
                  widget::canvas::win32 * w32c = dynamic_cast<widget::canvas::win32*>( this->canvas_protected() );
                  if( nullptr != w32c )
                   {
                    w32c->size( { width, height } );
                   }
                 }

                } return true;
              }

             return false;
            }

       };

     }
   }
 }

#endif
