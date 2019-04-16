#ifndef RATIONAL_H
#define RATIONAL_H

#include "Real.h"

class Rational : public Real
{
public:
    const double getRealPart() const override final;
    Rational();
    Rational(int numerator, int denominator);
    int getNumerator() const;
    int getDenominator() const;
    Rational add(const Rational& secondRational) const;
    Rational subtract(const Rational& secondRational) const;
    Rational multiply(const Rational& secondRational) const;
    Rational divide(const Rational& secondRational) const;
    int compareTo(const Rational& secondRational) const;
    bool equals(const Rational& secondRational) const;
    int intValue() const;
    double doubleValue() const;
    std::string toString() const override final;

    Rational(int numerator); // Suitable for type conversion

    // Define function operators for augmented operators
    Rational& operator+=(const Rational& secondRational);
    Rational& operator-=(const Rational& secondRational);
    Rational& operator*=(const Rational& secondRational);
    Rational& operator/=(const Rational& secondRational);

    // Define function operator []
    int& operator[](int index);

    // Define function operators for prefix ++ and --
    Rational& operator++();
    Rational& operator--();

    // Define function operators for postfix ++ and --
    Rational operator++(int dummy);
    Rational operator--(int dummy);

    // Define function operators for unary + and -
    Rational operator+();
    Rational operator-();

    // Define the << and >> operators
    friend std::ostream& operator<<(std::ostream&, const Rational&);
    friend std::istream& operator>>(std::istream&, Rational&);

private:
    int numerator;
    int denominator;
    static int gcd(int n, int d);
};

// Define nonmember function operators for relational operators
bool operator<(const Rational& r1, const Rational& r2);
bool operator<=(const Rational& r1, const Rational& r2);
bool operator>(const Rational& r1, const Rational& r2);
bool operator>=(const Rational& r1, const Rational& r2);
bool operator==(const Rational& r1, const Rational& r2);
bool operator!=(const Rational& r1, const Rational& r2);

// Define nonmember function operators for arithmetic operators
Rational operator+(const Rational& r1, const Rational& r2);
Rational operator-(const Rational& r1, const Rational& r2);
Rational operator*(const Rational& r1, const Rational& r2);
Rational operator/(const Rational& r1, const Rational& r2);

#endif

