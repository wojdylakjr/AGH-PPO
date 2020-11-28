#pragma once
#include<iostream>
typedef int counter;
void initCounter(int*);
double* initGeometricalSequence(int, double,int);
double* initArithmeticSequence(int, double,int);
void printSequence(const double*, int);
void deleteSequence(const double**);
void addSequence(const double***, double**,double *, int);
void printAllSequences(const double**, double*);
void deleteAllSequences (const double**, double*);