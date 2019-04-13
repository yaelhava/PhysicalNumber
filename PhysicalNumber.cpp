#include "PhysicalNumber.h"
#include "Unit.h"
//#include <string>

using namespace ariel;

PhysicalNumber PhysicalNumber::operator+ (const PhysicalNumber &num) const
{

    double ans;

    if ((int)this->type % 3 == (int)num.type % 3)
    {
        double thisTemp = convert(this->value, this->type);
        double numTemp = convert(num.value, num.type);
        ans = thisTemp + numTemp;
        return defineType(ans);
    }
    else
    {
        throw runtime_error("NOT THE SAME TYPE");
    }
}

PhysicalNumber PhysicalNumber::operator- (const PhysicalNumber &num) const
{
    PhysicalNumber temp((-1) * (num.value), num.type);
    return (*this + temp);
}

PhysicalNumber &PhysicalNumber::operator++ ()
{
    this->value++;
    return *this;
}

PhysicalNumber &PhysicalNumber::operator-- ()
{
    this->value--;
    return *this;
}

PhysicalNumber PhysicalNumber::operator++ (int)
{
    PhysicalNumber res(this->value, this->type);
    ++(*this);
    return res;
}

PhysicalNumber PhysicalNumber::operator-- (int)
{
     PhysicalNumber res(this->value, this->type);
    --(*this);
    return res;
}

PhysicalNumber &PhysicalNumber::operator+= (const PhysicalNumber &num)
{
    *this = *this + num;
    return *this;
}

PhysicalNumber PhysicalNumber::operator+ () const
{
    return *this;
}

// +A
PhysicalNumber &PhysicalNumber::operator-= (const PhysicalNumber &num)
{
    *this = *this - num;
    return *this;
}

// num = A-B
PhysicalNumber PhysicalNumber::operator- () const
{
    return PhysicalNumber((-1) * this->value, this->type);
} // -A




bool PhysicalNumber::operator>= (const PhysicalNumber num) const
{
    if ((int)this->type % 3 == (int)num.type % 3)
    {
        double thisTemp = convert(this->value, this->type);
        double numTemp = convert(num.value, num.type);
        return thisTemp >= numTemp;
    }
    else
    {
        throw runtime_error("NOT THE SAME TYPE");
    }
}


bool PhysicalNumber::operator<= (const PhysicalNumber num) const
{
    if ((int)this->type % 3 == (int)num.type % 3)
    {
        double thisTemp = convert(this->value, this->type);
        double numTemp = convert(num.value, num.type);
        return thisTemp <= numTemp;
    }
    else
    {
        throw runtime_error("NOT THE SAME TYPE");
    }
}


bool PhysicalNumber::operator< (const PhysicalNumber num) const
{
    if(*this <= num && !(*this >= num)){
        return true;
    }
    return false;
}


bool PhysicalNumber::operator> (const PhysicalNumber num) const
{
    if(!(*this <= num) && *this >= num){
        return true;
    }
    return false;
}


bool PhysicalNumber::operator== (const PhysicalNumber num) const
{
    if(*this <= num && *this >= num){
        return true;
    }
    return false;
}


bool PhysicalNumber::operator!= (const PhysicalNumber num) const
{
   bool flag = *this == num;
    return !flag;
}


std::ostream &ariel::operator<< (ostream &os, const PhysicalNumber &num)
{
    char const *units[] = {"cm", "sec", "g", "m", "min", "kg", "km", "hour", "ton"};
    os << num.value << "[" << units[(int)num.type] << "]";
    return os;
}

std::istream &ariel::operator>> (istream &is, const PhysicalNumber &num)
{
    return is;
}

double PhysicalNumber::convert(double val, Unit t) const
{
    double result;

    if ((int)this->type % 3 == 0)
    {
        switch (t)
        {
        case Unit::M:
            result = val * 100;
            break;
        case Unit::KM:
            result = val * 100000;
            break;
        default:
            result = val;
        }
    }
    else if ((int)this->type % 3 == 1)
    {
        switch (t)
        {
        case Unit::MIN:
            result = val * 60;
            break;
        case Unit::HOUR:
            result = val * 3600;
            break;
        default:
            result = val;
        }
    }
    else if ((int)this->type % 3 == 2)
    {
        switch (t)
        {
        case Unit::KG:
            result = val * 1000;
            break;
        case Unit::TON:
            result = val * 1000000;
            break;
        default:
            result = val;
        }
    }
    return result;
}

PhysicalNumber PhysicalNumber::defineType(double val) const
{
    PhysicalNumber result;

    if ((int)this->type % 3 == 0)
    {
        switch (this->type)
        {
        case Unit::M:
            result = PhysicalNumber(val / 100, this->type);
            break;
        case Unit::KM:
            result = PhysicalNumber(val / 100000, this->type);
            break;
        default:
            result = PhysicalNumber(val, this->type);
        }
    }
    else if ((int)this->type % 3 == 1)
    {
        switch (this->type)
        {
        case Unit::MIN:
            result = PhysicalNumber(val / 60, this->type);
            break;
        case Unit::HOUR:
            result = PhysicalNumber(val / 3600, this->type);
            break;
        default:
            result = PhysicalNumber(val, this->type);
        }
    }
    else if ((int)this->type % 3 == 2)
    {
        switch (this->type)
        {
        case Unit::KG:
            result = PhysicalNumber(val / 1000, this->type);
            break;
        case Unit::TON:
            result = PhysicalNumber(val / 1000000, this->type);
            break;
        default:
            result = PhysicalNumber(val, this->type);
        }
    }
    return result;
}

// int main()
// {
//     cout << "hi" << endl;
//     PhysicalNumber p(3, Unit::HOUR);
//     PhysicalNumber t(10, Unit::SEC);

//     cout << p + t << endl;
//     cout << t + p << endl;

//     cout << "***************1****************" << endl;

//     //cout << (p+=t) << endl;

//     cout << (p -= t) << endl;

//     cout << "**************2*****************" << endl;

//     cout << (++p) << endl;
//     cout << (--p) << endl;

//     cout << "***************3****************" << endl;

//     PhysicalNumber a(6, Unit::M);
//     PhysicalNumber b(5, Unit::KM);

//     cout << a - b << endl;
//     cout << b - a << endl;

//     cout << "**************4*****************" << endl;

//     cout << -a << endl;

//     cout << "***************5****************" << endl;

//     PhysicalNumber x(60, Unit::MIN);
//     PhysicalNumber y(1, Unit::HOUR);

//     //  cout << "x now is: " << x << endl;

//     // cout << (x++) << endl;
//     //      cout << "x now is: " << x << endl;

//     //  cout << (x--) << endl;
//       cout << "x now is: " << x << endl;

//  cout << "***************6****************" << endl;

//     bool flag = y != x;
//     cout << flag << endl;
//           cout << "y now is: " << y << endl;

    
//     return 0;
// }