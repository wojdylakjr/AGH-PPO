#pragma once
#include "Fraction.h"
class FractionArray{
    public:
    FractionArray(int);
    ~FractionArray();

    Fraction& operator [](int);
    const Fraction& operator[](unsigned index) const;

    private:
    int _size;
    Fraction *_array;
};