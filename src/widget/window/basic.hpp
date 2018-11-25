#ifndef widget_window_basic
#define widget_window_basic

// widget::window::basic< size_name, position_name, dimension_number >


#include "./pure.hpp"
#include "../canvas/devnull.hpp"
#include "../event/generator/idle.hpp"
#include "./exchange/process.hpp"

namespace widget
 {
  namespace window
   {

    template< typename size_name, typename position_name, unsigned dimension_number >
     class basic
      : public ::widget::window::pure< size_name, position_name, dimension_number>
      {
       public:

         typedef ::widget::window::pure< size_name, position_name, dimension_number> pure_type;
         typedef ::widget::window::basic< size_name, position_name, dimension_number> basic_type;

         typedef ::widget::event::generator::pure  generator_type;
         typedef ::widget::event::consumer::pure    consumer_type;

         typedef ::widget::type::dumb_ptr< canvas_type >         canvas_ptr_type;
         typedef ::widget::type::dumb_ptr< generator_type  >  generator_ptr_type;
         typedef ::widget::type::dumb_ptr< consumer_type  >    consumer_ptr_type;

         typedef widget::event::pure event_type;

         basic()
          {
           m_generator = new ::widget::event::generator::idle;
           //m_canvas    = this;
           //m_consumer  = this;
           m_generator->consumer( this );
          }

         virtual ~basic() { }

         virtual operator generator_type&()
          {
           return *m_generator;
          }

         //virtual operator canvas_type&()
         // {
         //  return *m_canvas;
         // }
         //
         //virtual operator consumer_type&()
         // {
         //  return *m_consumer;
         // }

         bool run()
          {
           if( true == this->m_generator->active() )
            {
             return true;
            }

           if( false == ::widget::window::exchange::prepare::process( *this, * this->m_generator ) )
            {
             return false;
            }

           if( false == this->m_generator->run() )
            {
             return false;
            }

           if( false == ::widget::window::exchange::report::process( *this, * this->m_generator ) )
            {
             return false;
            }

           return true;
          }

         void stop()
          {
           if( false == this->active() )
            {
             return;
            }

           this->active_protected().store( false );

           this->m_generator->stop();
          }

         bool process( event_type const & e )
          {
           return m_consumer->process( e );
          }

      //public:
      //   virtual canvas_ptr_type    const& canvas()const{ return m_canvas; }
      //   virtual void canvas( canvas_ptr_type const& canvas_param )
      //    {
      //     m_canvas = canvas_param;
      //    }
      // protected:
      //   canvas_ptr_type        & canvas_protected(){ return m_canvas; }
      // private:
      //   canvas_ptr_type m_canvas;

       public:
         virtual consumer_ptr_type    const& consumer()const { return m_consumer; }
         virtual void consumer( consumer_ptr_type const& consumer_param)
          {
           m_consumer = consumer_param;
          }
       protected:
         consumer_ptr_type        & consumer_protected() { return m_consumer; }
       private:
         consumer_ptr_type m_consumer;

       public:
         virtual generator_ptr_type    const& generator()const{ return m_generator; }
         virtual void generator( generator_ptr_type const& generator_param )
          {
           m_generator = generator_param;
          }
       protected:
         generator_ptr_type        & generator_protected(){ return m_generator; }
       private:
         generator_ptr_type m_generator;

      };

    }
}

#endif
