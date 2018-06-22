#ifndef FRACTION
#define FRACTION

#include <iostream>
#include <cstdlib>
#include <exception>
#include <string>
#include <regex>


//exception classes
class invalidFraction:public std::exception
{
    public:
    const char * what() const throw()
    {
        return "Invalid fraction entered";
    };

};

class divByZero:public std::exception
{
    public:
    const char * what() const throw()
    {
        return "Division by zero";
    };
};

//utility functions
int gcd(int, int);
int lcm(int, int);

class fraction
{
    private:
    int num;
    int den;

    public:
    //contructors
    fraction(void);
    fraction(const std::string&);
    fraction(const int&, const int&);
    fraction(const fraction&);

    //get
    int getNumerator(void) const;
    int getDenominator(void) const;

    //I/O
    friend std::istream& operator>>(std::istream&, fraction&);
    friend std::ostream& operator<<(std::ostream&, const fraction&);

    //arithmetic operators
    fraction operator+(const fraction&) const;
    fraction operator-(const fraction&) const;
    fraction operator*(const fraction&) const;
    fraction operator/(const fraction&) const;

    //relational operators
    bool operator==(const fraction&) const;
    bool operator!=(const fraction&) const;
    bool operator<(const fraction&) const;
    bool operator<=(const fraction&) const;
    bool operator>(const fraction&) const;
    bool operator>=(const fraction&) const;

    //casting
    float toFloat() const;

};


#endif