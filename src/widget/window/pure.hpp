#ifndef widget_window_pure
#define widget_window_pure

// widget::element::pure

#include <set>
#include <map>

#include "../type/id.hpp"

#include "../canvas/crop.hpp"
#include "../canvas/collection.hpp"
#include "../event/consumer/pure.hpp"


namespace widget
 {
  namespace window
   {

    template< typename size_name, typename position_name, unsigned dimension_number >
     class pure
      : public virtual ::widget::canvas::crop< size_name, position_name, dimension_number>
      , public virtual ::widget::canvas::collection< size_name, position_name, dimension_number>
      , public virtual ::widget::event::consumer::pure
      {
       public:
         typedef ::widget::canvas::pure< size_name, position_name, dimension_number >            canvas_type;
         typedef ::widget::canvas::crop< size_name, position_name, dimension_number >              crop_type;
         typedef ::widget::canvas::collection< size_name, position_name, dimension_number >  collection_type;
         typedef ::widget::event::consumer::pure                                               consumer_type;

         pure( )
          {
          }

         virtual ~pure() { }

      };

   }
 }

#endif
