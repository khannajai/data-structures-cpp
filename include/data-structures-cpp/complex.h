#ifndef COMPLEX
#define COMPLEX

#include <iostream>
#include <tuple>

class complex
{
    private:
    float real;
    float imag;

    public:
    complex(void);
    complex(const float&, const float&);
    complex(const complex&);

    float getReal(void) const;
    float getImag(void) const;

    //overloading
    friend std::ostream& operator<<(std::ostream&, const complex&);
    friend std::istream& operator>>(std::istream&, complex&);

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
};

#endif