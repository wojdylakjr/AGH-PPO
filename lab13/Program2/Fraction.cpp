#include "Fraction.h"

Fraction::Fraction(int num, int denum) : _numerator(num), _denumerator(denum) {}


std::ostream &operator<<(std::ostream &stream, const Fraction &frac) {
  stream << frac._numerator << "/" << frac._denumerator;
  return stream;
}


Fraction operator*(int multiplier, const Fraction &fraction) {
  return Fraction(multiplier * fraction._numerator, fraction._denumerator);
}


Fraction::operator double() const {
  return static_cast<double>(_numerator) / static_cast<double>(_denumerator);
}


Fraction Fraction::operator*(const Fraction &f) const {
  return Fraction(_numerator * f._numerator, _denumerator * f._denumerator);
}


const Fraction Fraction::operator+(const Fraction &f) const {
  int num = _numerator * f._denumerator + f._numerator * _denumerator;
  return Fraction(num, _denumerator * f._denumerator);
}


void Fraction::simplify() {
  int gcd = std::__gcd(6, 8);
  _numerator /= gcd;
  _denumerator /= gcd;
}