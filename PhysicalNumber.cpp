#include "PhysicalNumber.h"
#include "Unit.h"
//#include <string>

using namespace ariel;



PhysicalNumber PhysicalNumber::operator+ (const PhysicalNumber& num ) const{
    
    double ans;

    if((int)this->type % 3 == (int)num.type % 3){
        double thisTemp = convert(this->value, this->type);
        double numTemp = convert(num.value, num.type);
        ans = thisTemp + numTemp;
        return defineType(ans);
    }
    else{
        throw runtime_error("NOT THE SAME TYPE");
    }    
}


PhysicalNumber PhysicalNumber::operator- (const PhysicalNumber& num ) const{
    PhysicalNumber temp((-1) * (num.value), num.type);
    return (*this + temp);
}


PhysicalNumber& PhysicalNumber::operator++ () {
    this->value++;
    return *this;
}


PhysicalNumber& PhysicalNumber::operator-- () {
    this->value--;
    return *this;
}


PhysicalNumber PhysicalNumber::operator++  (int){
    //PhysicalNumber res(this->value, this->type);
    ++(*this);
    return res;
}


PhysicalNumber& PhysicalNumber::operator--  (int){

}


PhysicalNumber& PhysicalNumber::operator+= (const PhysicalNumber& num ){
    *this = *this + num;
    return *this;
}


PhysicalNumber PhysicalNumber::operator+() const {
    return *this;
}

// +A
PhysicalNumber& PhysicalNumber::operator-= (const PhysicalNumber& num ){
    *this = *this - num;
    return *this;
}

 // num = A-B
PhysicalNumber PhysicalNumber::operator-() const {  
    return PhysicalNumber((-1) * this->value, this->type);
} // -A



bool PhysicalNumber::operator<  (const PhysicalNumber num ) const{
    return false;
}
bool PhysicalNumber::operator<= (const PhysicalNumber num )const{
    return false;
}
bool PhysicalNumber::operator>= (const PhysicalNumber num )const{
    return false;
}
bool PhysicalNumber::operator>  (const PhysicalNumber num )const{
    return false;
}
bool PhysicalNumber::operator== (const PhysicalNumber num )const{
    return false;
}
bool PhysicalNumber::operator!= (const PhysicalNumber num )const{
    return false;
}


std::ostream& ariel::operator<< (ostream& os, const PhysicalNumber& num){
    char* units[] = {"cm", "sec", "g", "m", "min", "kg", "km", "hour", "ton"};
    os << num.value << "[" << units[(int)num.type] << "]";
    return os;
}


std::istream& ariel::operator>> (istream& is, const PhysicalNumber& num){
    return is;

} 



double PhysicalNumber::convert(double val, Unit t) const
{
    if ((int)this->type % 3 == 0){
        switch (t)
        {
            case Unit::CM:
                return val;
                break;
            case Unit::M:
                return val * 100;
                break;
            case Unit::KM:
                return val * 100000;
                break;
       
        }
    }
    if ((int)this->type % 3 == 1)
    {
        switch (t)
        {
            case Unit::SEC:
                return val;
                break;
            case Unit::MIN:
                return val * 60;
                break;
            case Unit::HOUR:
                return val * 3600;
                break;
        }
    }
    if ((int)this->type % 3 == 2){
        switch (t)
        {
            case Unit::G:
                return val;
                break;
            case Unit::KG:
                 return val * 1000;
                break;
            case Unit::TON:
                return val * 1000000;
                break;
        }
    }
}


PhysicalNumber PhysicalNumber::defineType(double val) const{
        if ((int)this->type % 3 == 0){
            switch (this->type)
            {
                case Unit::CM:
                    return PhysicalNumber(val, this->type);
                    break;
                case Unit::M:
                    return PhysicalNumber(val / 100, this->type);
                    break;            
                case Unit::KM:
                    return PhysicalNumber(val / 100000, this->type);
                    break;                
            }
        }
        if((int)this->type % 3 == 1){
            switch (this->type)
            {
                case Unit::SEC:
                    return PhysicalNumber(val, this->type);
                    break;
                case Unit::MIN:
                    return PhysicalNumber(val / 60, this->type);
                    break;            
                case Unit::HOUR:
                    return PhysicalNumber(val / 3600, this->type);
                    break;                
            }
        } 
        if((int)this->type % 3 == 2){
            switch (this->type)
            {
                case Unit::G:
                    return PhysicalNumber(val, this->type);
                    break;
                case Unit::KG:
                    return PhysicalNumber(val / 1000, this->type);
                    break;            
                case Unit::TON:
                    return PhysicalNumber(val / 1000000, this->type);
                    break;                
            }
        }   
}








int main(){
    cout << "hi" << endl;
    PhysicalNumber p(3, Unit::HOUR);
    PhysicalNumber t(10, Unit::SEC);

    cout << p+t << endl;
    cout << t+p << endl;

    cout << "***************1****************" << endl;

  //cout << (p+=t) << endl;

    cout << (p-=t) << endl;



       cout << "**************2*****************" << endl;

   cout << (++p) << endl;
    cout << (--p) << endl;



    cout << "***************3****************" << endl;


    PhysicalNumber a(6, Unit::M);
    PhysicalNumber b(5, Unit::KM);

    cout << a-b << endl;
    cout << b-a << endl;

    cout << "**************4*****************" << endl;
    
    cout << -a << endl;

    cout << "***************5****************" << endl;


    PhysicalNumber x(6, Unit::CM);
    PhysicalNumber y(5, Unit::CM);   
    

   cout << (p++) << endl;
   // cout << (--p) << endl;     

    return 0;
}