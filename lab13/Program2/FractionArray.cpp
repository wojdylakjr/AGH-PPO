#include "FractionArray.h"

FractionArray::FractionArray(int size) : _size(size) {
  _array = new Fraction[_size];
}


FractionArray::~FractionArray() { 
    delete[] _array; 
}


Fraction &FractionArray::operator[](int index) {
     return _array[index];
}


const Fraction &FractionArray::operator[](unsigned index) const {
  return _array[index];
}