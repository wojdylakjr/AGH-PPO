#include "lab06.h"
#include <iostream>
#include <math.h>

void set(Bits *bits, int *data, int size) {
  bits->size = size;
  for (int i = 0; i < bits->size; i++) {
    bits->bitsArray[i] = data[i];
  }
}

void print(const Bits *bits) {

  for (int i = 0; i < bits->size; i++) {
    std::cout << bits->bitsArray[i];
  }
  std::cout << std::endl;
}

const Bits add_up(Bits *bits1, Bits *bits2) {
  Bits sum;
  int maxSize = 0;
  int minSize = 0;

  if (bits1->size > bits2->size) {
    maxSize = bits1->size;
    minSize = bits2->size;
  } else {
    maxSize = bits2->size;
    minSize = bits1->size;
  }

  sum.size = maxSize;
  int counter = 0;
  int added = 0;

  //dodanie wartosci z tablic (idac od konca) tyle razy ile jest cyfr w mniejszej z tablic, zapelnienie indeksow [maxSize-minSize;maxSize] tablicy sum.bitsArray[]
  for (int i = 0; i < minSize; i++) {
    added = bits1->bitsArray[bits1->size - 1 - i] + bits2->bitsArray[bits2->size - 1 - i] + counter;
    if (added == 0 || added == 1) {
      sum.bitsArray[maxSize - 1 - i] = added;
      counter = 0;
    } else if (added == 2) {
      sum.bitsArray[maxSize - 1 - i] = 0;
      counter = 1;
    } else if (added == 3) {
      sum.bitsArray[maxSize - 1 - i] = 1;
      counter = 1;
    } else {
      exit(1);
    }
  }
  //uzupelnienie wartosci w tablicy struktury sum w przedziale [0;maxSize-minSize-1], w zaleznosci od tego, ktora z tablic byla wieksza 
  if (bits1->size > bits2->size) {
    sum.bitsArray[maxSize - minSize - 1] = bits1->bitsArray[maxSize - minSize - 1] + counter;//dodanie z uwzglednieniem reszty
    for (int i = maxSize - minSize - 2; i >= 0; i--) { //przepisanie wartosci z wiekszej tablicy
      sum.bitsArray[i] = bits1->bitsArray[i];
    }
  } else {
    sum.bitsArray[maxSize - minSize - 1] = bits2->bitsArray[maxSize - minSize - 1] + counter;
    for (int i = maxSize - minSize - 2; i >= 0; i--) {
      sum.bitsArray[i] = bits2->bitsArray[i];
    }
  }

  return sum;
}

void bit_and(Bits *bits, Bits *mask) {
  for (int i = 0; i < bits->size; i++) {
    bits->bitsArray[i] = mask->bitsArray[i] & bits->bitsArray[i];
  }
}

void bit_xor(Bits *bits, Bits *mask) {
  for (int i = 0; i < bits->size; i++) {
    if ((bits->bitsArray[i] == 1 && mask->bitsArray[i] == 0) || (bits->bitsArray[i] == 0 && mask->bitsArray[i] == 1)) {
      bits->bitsArray[i] = 1;
    } else {
      bits->bitsArray[i] = 0;
    }
  }
}

int to_decimal(const Bits *bits) {
  int number = 0;
  int counter = 0;
  for (int i = bits->size - 1; i >= 0; i--) {

    number = number + pow(2, counter) * bits->bitsArray[i];
    counter++;
  }

  return number;
}