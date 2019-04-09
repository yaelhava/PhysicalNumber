#include <iostream>
using namespace std;
#include "Unit.h"

namespace ariel{

    
    class PhysicalNumber{

        public:
        double value;
        Unit type;

        PhysicalNumber(double num,Unit t){
            value = num;
            type = t;
        }

        PhysicalNumber operator+   (const PhysicalNumber& a ) const;
        PhysicalNumber operator-   (const PhysicalNumber& a ) const;
        PhysicalNumber& operator++  () ;
        PhysicalNumber& operator--  () ;
        PhysicalNumber& operator+=      (const PhysicalNumber& a );
        PhysicalNumber operator+() const;
        PhysicalNumber& operator-=      (const PhysicalNumber& a );
        PhysicalNumber operator-() const;


        bool operator<  (const PhysicalNumber a) const;
        bool operator<= (const PhysicalNumber a) const;
        bool operator>= (const PhysicalNumber a)const;
        bool operator>  (const PhysicalNumber a)const;
        bool operator== (const PhysicalNumber a)const;
        bool operator!= (const PhysicalNumber a)const;

        friend ostream& operator<< (ostream& a, const PhysicalNumber& b);
        friend istream& operator>> (istream& a, const PhysicalNumber& b); 
        
    
        


       
        
    };

}