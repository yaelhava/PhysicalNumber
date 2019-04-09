#include "PhysicalNumber.h"
#include "Unit.h"

using namespace ariel;

PhysicalNumber PhysicalNumber::operator+   (const PhysicalNumber& a ) const{
    return *this;
} // +A
PhysicalNumber PhysicalNumber::operator-   (const PhysicalNumber& a ) const{
    return *this;
}
PhysicalNumber& PhysicalNumber::operator++  () {
    return *this;
}
PhysicalNumber& PhysicalNumber::operator--  () {
    return *this;
}
PhysicalNumber& PhysicalNumber::operator+=        (const PhysicalNumber& a ){
    return *this;
}
PhysicalNumber PhysicalNumber::operator+() const {
    return *this;
} // +A
PhysicalNumber& PhysicalNumber::operator-= (const PhysicalNumber& a ){
    return *this;
} // A = A-B
PhysicalNumber PhysicalNumber::operator-() const {
    return *this;
} // -A


bool PhysicalNumber::operator<  (const PhysicalNumber a) const{
    return false;
}
bool PhysicalNumber::operator<= (const PhysicalNumber a)const{
    return false;
}
bool PhysicalNumber::operator>= (const PhysicalNumber a)const{
    return false;
}
bool PhysicalNumber::operator>  (const PhysicalNumber a)const{
    return false;
}
bool PhysicalNumber::operator== (const PhysicalNumber a)const{
    return false;
}
bool PhysicalNumber::operator!= (const PhysicalNumber a) const{
    return false;
}


std::ostream& ariel::operator<< (ostream& a, const PhysicalNumber& b){
    return a;
}
std::istream& ariel::operator>> (istream& a, const PhysicalNumber& b){
    return a;

} 

// int main(){
//     cout << "hi";
//     return 0;
// }