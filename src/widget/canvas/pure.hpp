#ifndef widget_canvas_pure
#define widget_canvas_pure

// widget::canvas::pure





namespace widget
 {
  namespace canvas
   {

    template< typename size_name, typename position_name, unsigned dimension_number >
     class pure
      {
       public:
         typedef size_name           size_type;
         typedef position_name   position_type;

         typedef widget::canvas::pure< size_name, position_name, dimension_number > pure_type;

         pure(){ }
       //pure( pure const& original ){ *this = P_original; }
        virtual ~pure(){ }
       //pure & operator=( pure const& original ){ return *this; }

       public:
         virtual void lock(){  }
         virtual void unlock(){  }
         bool volatile const& status()const { return m_status; }
       private:
         volatile bool m_status;
      };

   }
 }

#endif
