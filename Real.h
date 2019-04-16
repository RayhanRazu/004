#ifndef REAL_H
#define REAL_H

#include "Number.h"

class Real : public Number
{
    public:
        virtual bool operator<(const Real& real) const final;
        virtual bool operator<=(const Real& real)  const final;
        virtual bool operator>(const Real& real)  const final;
        virtual bool operator>=(const Real& real)  const final;
        const double getImaginaryPart() const override final;
};

#endif // REAL_H
