#pragma once
#include<iostream>

typedef struct Vector{
int nDim;
int* vectorArray;
}Vector;

typedef struct Matrix{
int nDim;
int sizeOfArrays;
int* matrixArray;
}Matrix;

Vector* form_Vector(int a=0, int b=0);
const Matrix* form_Matrix(int a=0, int b=0, int c=0);
void print(Vector);
void print(const Matrix);
void deleteAll(Vector*);
void deleteAll(const Matrix*);
bool addFirstToSecond(Vector&, Vector&);
void setNewDimension(Vector&, int);
// void  deleteAll(&Vector);
// void  deleteAll(&Matrix);