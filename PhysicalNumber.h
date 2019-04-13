#include <iostream>
using namespace std;
#include "Unit.h"

namespace ariel{

    
    class PhysicalNumber{

        public:
        double value;
        Unit type;

        PhysicalNumber(){}
        PhysicalNumber(double num,Unit t){
            value = num;
            type = t;
        }

        // PhysicalNumber(PhysicalNumber &pn){
        //     value = pn.value;
        //     type = pn.type;
        // }

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


        bool operator>=  (const PhysicalNumber num ) const;
        bool operator<= (const PhysicalNumber num ) const;
        bool operator< (const PhysicalNumber num )const;
        bool operator>  (const PhysicalNumber num )const;
        bool operator== (const PhysicalNumber num )const;
        bool operator!= (const PhysicalNumber num )const;

        friend ostream& operator<< (ostream& os , const PhysicalNumber& num );
        friend istream& operator>> (istream& is , const PhysicalNumber& num ); 
        
    
        private:
        double convert(double val, Unit t) const;
        PhysicalNumber defineType(double val) const;





       
        
    };

}