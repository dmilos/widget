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

         virtual operator pure_type  (){return *this;}
         virtual operator pure_type const  ()const{ return *this;}
         virtual operator pure_type& (){return *this;}
         virtual operator pure_type const& ()const{ return *this;}

         virtual pure_type      * operator&()       { return this; }
         virtual pure_type const* operator&() const { return this; }

       public:
         virtual void lock(){  }
         virtual void unlock(){  }
         bool volatile const& status()const { return m_status; }

       protected:
         typedef class protector
          {
           public:
             protector( pure_type & pure ):m_pure( pure ){ m_pure.lock(); }
            ~protector( ){ m_pure.unlock(); }

           private:
            pure_type & m_pure;
          }protector_type;

       private:
         volatile bool m_status;

       public:
         static unsigned dimension(){ return dimension_number; }
      };

   }
 }

#endif
