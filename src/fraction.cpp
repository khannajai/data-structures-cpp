#include <iostream>
#include <cstdlib>
#include <exception>
#include <string>
#include <regex>

#include "fraction.h"

int gcd(int a, int b)
{
    // base case
    if (a == b)
        return a;
 
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

int lcm(int a, int b)
{
    return (a*b)/gcd(a, b);
}

float fraction::toFloat() const
{
    return (float)(num)/(float)(den);
}

fraction::fraction(void)
{
}

fraction::fraction(const std::string& info)
{
    std::regex f("((\\+|-)?[[:digit:]]+)*/((\\+|-)?[[:digit:]]+)");
    if(!std::regex_match(info,f))
    {
        throw invalidFraction();
        return;
    }
    std::string frac=info;
    std::string delim="/";
    auto pos = frac.find(delim);
    
    std::string numerator = frac.substr(0, pos);
    int nume=std::stoi(numerator);
    frac.erase(0,pos+delim.length());
    
    std::string denominator=frac;
    int deno=std::stoi(denominator);
    if(deno==0)
    {
        throw divByZero();
        return;
    }
    num=nume;
    den=deno;
}

fraction::fraction(const int& n, const int& d)
{
    if(d==0)
    {
        throw divByZero();
        return;
    }
    num=n;
    den=d;
}

fraction::fraction(const fraction& other)
{
    num=other.num;
    den=other.den;
}

int fraction::getNumerator(void) const
{
    return num;
}

int fraction::getDenominator(void) const
{
    return den;
}

std::istream& operator>>(std::istream& in, fraction& frac)
{
    std::cout<<"Enter a numerator: ";
    in>>frac.num;
    std::cout<<"Enter a denominator: ";
    int temp;
    in>>temp;
    if(temp==0)
    {
        throw divByZero();
        return in;
    }
    frac.den=temp;
    return in;
}

std::ostream& operator<<(std::ostream& out, const fraction& frac)
{
    out<<frac.num<<"/"<<frac.den;
    return out;
}

//arithmetic operators
fraction fraction::operator+(const fraction& other) const
{
    fraction result;
    result.den=lcm(den,other.den);
    result.num=(result.den/den)*num+(result.den/other.den)*other.num;
    return result;
}

fraction fraction::operator-(const fraction& other) const
{
    fraction result;
    result.den=lcm(den,other.den);
    result.num=(result.den/den)*num-(result.den/other.den)*other.num;
    return result;
}

fraction fraction::operator*(const fraction& other) const
{
    fraction result;
    result.num=num*other.num;
    result.den=den*other.den;
    return result;
}

fraction fraction::operator/(const fraction& other) const
{
    fraction result;
    result.num=num*other.den;
    result.den=den*other.num;
    return result;
}

//relational operators
bool fraction::operator==(const fraction& other) const
{
    return(toFloat()==other.toFloat());
}

bool fraction::operator!=(const fraction& other) const
{
    return(toFloat()!=other.toFloat());
}

bool fraction::operator<(const fraction& other) const
{
    return(toFloat()<other.toFloat());
}

bool fraction::operator<=(const fraction& other) const
{
    return(toFloat()<=other.toFloat());
}

bool fraction::operator>(const fraction& other) const
{
    return(toFloat()>other.toFloat());
}

bool fraction::operator>=(const fraction& other) const
{
    return(toFloat()>=other.toFloat());
}