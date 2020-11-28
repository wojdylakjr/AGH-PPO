#ifndef LAB03_H
#define LAB03_H
#define MAX_SIZE 50
#include <iostream>

typedef struct myArray{
  int N=0;
  int tab[MAX_SIZE]={0};
  myArray *adress=NULL;
} myArray;

void printArray(myArray);
int fillArrayWithFibonacci(myArray*, int);
void extend(myArray*, int);
void truncate(myArray*, int);
void revert(myArray*);
void checkArraySpouse(myArray*);
void marry(myArray*, myArray*);
void divorce(myArray*, myArray*);
myArray formChild(myArray*, myArray*);
void printParents(myArray*);
int generateFibonaci(int);
void swap(int *, int *);
#endif