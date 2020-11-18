#ifndef LAB01_H //czy to dobra nazwa? oczywiscie ze tak, to nie ma wplywu na dzialanie programu wiec moze byc wszystko co Panu odpowiada i ma jako-taki sens
#define LAB01_H
#include <iostream>
typedef struct vecN{
  int N = 0;
  int tab[50];
  vecN *adress=NULL;
} vecN;
void printVec (vecN *);
int fillVecWithFibonacci(vecN*, int numberOfFibonacci);
int generateFibonacci(int);
void swap(vecN*,vecN*);
void revert (vecN *);
void truncate (vecN *,int);
void extend (vecN *,int);
void checkVecSpouse(vecN *);
void marry (vecN*,vecN*);
void divorce (vecN*,vecN*);
void swapNumbers (int *, int *);
#endif
//tu chyba czegos brakuje (pewnej dyrektywy preprocesora skoro uzyl Pan ifndef)
//Dziekuje