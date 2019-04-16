#ifndef NUMBER_H
#define NUMBER_H
#include <iostream>

class Number
{
public:
    virtual std::string toString() const = 0 ;
    virtual const double getRealPart() const = 0;
    virtual const double getImaginaryPart() const = 0;
    virtual bool operator==(const Number& number) const final;
    virtual bool operator!=(const Number& number) const final;
};

const static double INFINITELY_SMALL = 0.000001;
#endif // NUMBER_H
