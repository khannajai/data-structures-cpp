#include "complex.h"
#include <iostream>

complex::complex(void)
{

}

complex::complex(const float& r, const float& i):real(r), imag(i)
{

}

complex::complex(const complex& other):real(other.real), imag(other.imag)
{

}

//overloading
std::ostream& operator<<(std::ostream& out, const complex& c)
{
    out<<c.real<<" + "<<c.imag<<"j";
    return out;
}

std::istream& operator>>(std::istream& in, complex& c)
{
    std::cout<<"Enter the real part: ";
    in>>c.real;
    std::cout<<"Enter the imaginary part: ";
    in>>c.imag;
    return in;
}

float complex::getReal(void) const
{
    return real;
}
float complex::getImag(void) const
{
    return imag;
}

// bool operator==(const complex& other) const;
// bool operator<(const complex& other) const;
// bool operator<=(const complex& other) const;
// bool operator>(const complex& other) const;
// bool operator>=(const complex& other) const;
// bool operator!=(const complex& other) const;

// complex operator+(const complex& other) const;
// complex operator-(const complex& other) const;
// complex operator*(const complex& other) const;
// complex operator/(const complex& other) const;