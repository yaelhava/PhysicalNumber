#include <iostream>
#include "Unit.h"
#include <string.h>
#include <sstream>

using namespace std;

namespace ariel{

    //this class separate between units of measurement - distsnce, time and weight 

    class PhysicalNumber{

        public:
        double value;
        Unit type;

        PhysicalNumber(){}
        PhysicalNumber(double num,Unit t){
            value = num;
            type = t;
        }

                                                                            //aritmethic operators methods
        PhysicalNumber operator+   (const PhysicalNumber& num ) const;
        PhysicalNumber operator-   (const PhysicalNumber& num ) const;
        PhysicalNumber& operator++  ();
        PhysicalNumber& operator--  ();
        PhysicalNumber operator++  (int);
        PhysicalNumber operator--  (int);
        PhysicalNumber& operator+=  (const PhysicalNumber& num );
        PhysicalNumber operator+() const;
        PhysicalNumber& operator-=  (const PhysicalNumber& num );
        PhysicalNumber operator-() const;

                                                                            //boolean operators methods

        bool operator>=  (const PhysicalNumber num ) const;
        bool operator<= (const PhysicalNumber num ) const;
        bool operator< (const PhysicalNumber num )const;
        bool operator>  (const PhysicalNumber num )const;
        bool operator== (const PhysicalNumber num )const;
        bool operator!= (const PhysicalNumber num )const;
                                                                            //friends methods

        friend ostream& operator<< (ostream& os , const PhysicalNumber& num );
        friend istream& operator>> (istream& is ,  PhysicalNumber& num ); 
        
    
        private:
        double convert(double val, Unit t) const;
        PhysicalNumber defineType(double val) const;





       
        
    };

}