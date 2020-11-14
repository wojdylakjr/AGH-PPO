#pragma once
#include<iostream>

//struktura wektora zawiera wskaznik do tablicy jednowymiarowe oraz rozmiar tablicy
typedef struct Vector{
int nDim;
int* vectorArray;
}Vector;

//struktura wektora zawiera wskaznik do tablicy dwuwymiarowej i jej rozmiary
typedef struct Matrix{
int nDim;
int sizeOfArrays;
int** matrixArray;
}Matrix;

Vector* form_Vector(int a=3, int b=0); //funkcja tworzaca domyslny wektor, zwraca wektor, przyjmuje argumenty domniemane, pierwszy to rozmar, drugi domyslne wypelnienie
const Matrix* form_Matrix(int a=3, int b=3, int c=0);
void print(Vector&);
void print(const Matrix&);
void deleteAll(Vector*);
void deleteAll(const Matrix*);
bool addFirstToSecond(Vector&, Vector&);
void setNewDimension(Vector&, int);
// void  deleteAll(&Vector);
// void  deleteAll(&Matrix);