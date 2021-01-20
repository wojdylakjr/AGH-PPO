#pragma once
#include<iostream>
#include <algorithm>


class Fraction{
    public:
    
    Fraction(int num = 1, int denum = 1);

    friend std::ostream& operator<< (std::ostream& , const Fraction &);
    friend Fraction operator*(int multiplier, const Fraction& fraction);
    
    operator double() const;
    
    Fraction operator* (const Fraction & ) const;
    const Fraction operator+ (const Fraction &f) const;

    void simplify();
    
    private:
    int _numerator;
    int _denumerator;
};