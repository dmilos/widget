#ifndef widget_canvas_base
#define widget_canvas_base

// widget::canvas::base

#include "../type/position.hpp"
#include "../type/size.hpp"
#include "../type/rectangle.hpp"

#include "./pure.hpp"



namespace widget
 {
  namespace canvas
   {

    template< typename size_name, typename position_name, unsigned dimension_number >
     class crop
      : virtual public widget::canvas::pure< size_name, position_name, dimension_number >
      {
       public:
         typedef widget::canvas::pure< size_name, position_name, dimension_number > pure_type;

         typedef ::widget::type::rectangleNd_type< position_name, dimension_number > rectangleNd_type;
         typedef ::widget::type::sizeNd_type<         size_name, dimension_number > sizeNd_type;
         typedef ::widget::type::positionNd_type< position_name, dimension_number > positionNd_type;

         crop():m_client{{0,0},{1,1}}{}
        ~crop(){}

       public:
         rectangleNd_type    const& client()const{ return m_client; }
         virtual bool               client( rectangleNd_type const& client_param )
          {
           m_client = client_param;
           return bool( true );
          }
       protected:
         rectangleNd_type         & client_protected(){ return m_client; }
       private:
         rectangleNd_type m_client;

       public:
         positionNd_type    const& lo()const
          {
           return this->client_protected().first;
          }
         virtual bool               lo( positionNd_type const& lower )
          {
           this->client_protected().first = lower;
           return true;
          }

         positionNd_type    const& hi()const
          {
           return this->client_protected().first;
          }
         virtual bool               hi( positionNd_type const& upper )
          {
           this->client_protected().second = upper;
           return true;
          }

         sizeNd_type    const size()const
          {
           sizeNd_type s;
           for( decltype(s.size()) i=0; i< s.size();++i)
            {
             s[i] = this->client().second[i] - this->client().first[i];
            }
           return s;
          }

         virtual bool               size( sizeNd_type const& s )
          {
           for( decltype(s.size()) i=0; i< s.size();++i)
            {
             this->client_protected().second[i] = this->client_protected().first[i] + s[i];
            }
           return true;
          }

         virtual bool               offset( sizeNd_type const& o )
          {
           for( decltype(o.size()) i=0; i< o.size();++i)
            {
             auto  s = this->client_protected().second[i] - this->client_protected().first[i];
             this->client_protected().first[i] = o[i];
             this->client_protected().second[i] = o[i] + s;
            }
           return true;

          }


      };

   }
 }

#endif
