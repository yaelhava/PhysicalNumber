#include "PhysicalNumber.h"
#include "Unit.h"

using namespace ariel;


PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber &num) const           
{                                                                             // X + Y                      
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

PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber &num) const
{                                                                             // X - Y                      
    PhysicalNumber temp((-1) * (num.value), num.type);
    return (*this + temp);
}

PhysicalNumber &PhysicalNumber::operator++()
{                                                                             // ++X                    
    this->value++;
    return *this;
}

PhysicalNumber &PhysicalNumber::operator--()
{                                                                             // --X                     
    this->value--;
    return *this;
}

PhysicalNumber PhysicalNumber::operator++(int)
{                                                                             // X++                      
    PhysicalNumber res(this->value, this->type);
    ++(*this);
    return res;
}

PhysicalNumber PhysicalNumber::operator--(int)
{                                                                             // X--                      
    PhysicalNumber res(this->value, this->type);
    --(*this);
    return res;
}

PhysicalNumber &PhysicalNumber::operator+=(const PhysicalNumber &num)
{                                                                             // X += Y                     
    *this = *this + num;
    return *this;
}

PhysicalNumber PhysicalNumber::operator+() const
{                                                                             // X                     
    return *this;
}


PhysicalNumber &PhysicalNumber::operator-=(const PhysicalNumber &num)
{                                                                             // X -= Y                     
    *this = *this - num;
    return *this;
}


PhysicalNumber PhysicalNumber::operator-() const
{                                                                             // -X                     
    return PhysicalNumber((-1) * this->value, this->type);
} 


bool PhysicalNumber::operator>=(const PhysicalNumber num) const
{                                                                             // CHECK IF X >= Y                     
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

bool PhysicalNumber::operator<=(const PhysicalNumber num) const
{                                                                             // CHECK IF X <= Y                     
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

bool PhysicalNumber::operator<(const PhysicalNumber num) const
{                                                                             // CHECK IF X < Y                     
    if (*this <= num && !(*this >= num))
    {
        return true;
    }
    return false;
}

bool PhysicalNumber::operator>(const PhysicalNumber num) const
{                                                                             // CHECK IF X > Y                     
    if (!(*this <= num) && *this >= num)
    {
        return true;
    }
    return false;
}

bool PhysicalNumber::operator==(const PhysicalNumber num) const
{                                                                             // CHECK IF X == Y                     
    if (*this <= num && *this >= num)
    {
        return true;
    }
    return false;
}

bool PhysicalNumber::operator!=(const PhysicalNumber num) const
{                                                                             // CHECK IF X != Y                     
    bool flag = *this == num;
    return !flag;
}


std::ostream &ariel::operator<<(ostream &os, const PhysicalNumber &num)
{                                                                             // OUTPUT OF PhysicalNumber     
    char const *units[] = {"cm", "sec", "g", "m", "min", "kg", "km", "hour", "ton"};
    os << num.value << "[" << units[(int)num.type] << "]";
    return os;
}

std::istream &ariel::operator>>(istream &is, PhysicalNumber &num)
{                                                                             // INPUT OF PhysicalNumber     
    double temp;
    string str;
    is >> temp >> str;
    char const *units[] = {"cm", "sec", "g", "m", "min", "kg", "km", "hour", "ton"};
    int save = -1;
    bool isNotValid = true;

    if (str.find("[") != string::npos && str.find("]") != string::npos)
    {                                                                 //valid input
        for (int i = 0; i < 9; i++)
        {
            if (str.substr(str.find("[") + 1, str.length() - 2).compare(units[i]) == 0)
            {                                                                       //if equal
                save = i;
                isNotValid = false;
                break;
            }
            else
            {
                isNotValid = true;
            }
        }
    }

    if (isNotValid)
    {
        return is;
    }

    num.value = temp;
    num.type = static_cast<Unit>(save);

    return is;
}

double PhysicalNumber::convert(double val, Unit t) const
{                                                               //convert by type to the smallest unit
    double result;

    if ((int)this->type % 3 == 0)                               //distance
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
    {                                                           //time
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
    {                                                           //weight
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
{                                                              //return to original unit
    PhysicalNumber result;

    if ((int)this->type % 3 == 0)                               //distance
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
    {                                                           //time
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
    {                                                           //weight
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

