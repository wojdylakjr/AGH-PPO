#include"lab07.h"
#include<iostream>

Vector* form_Vector(int a, int b){
Vector *vec = new Vector;
vec->nDim=a;
vec->vectorArray = new int[a]();
for(int i=0;i<a;i++){
  vec->vectorArray[i]=b;
}


return vec;
}

const Matrix* form_Matrix(int a, int b, int c){
Matrix* mat = new Matrix;
mat->nDim=a;
mat->sizeOfArrays=b;
mat->matrixArray = new  int*[a]();
for(int i=0;i<a;i++){
  mat->matrixArray[i] = new int[a]();
}

for(int i=0;i<a;i++){
  for(int j=0;j<b;j++){
  mat->matrixArray[i][j]=c;
  }
   std::cout<<"]";
}



return mat;
}

void print(Vector& vec){
std::cout<<"[";

for(int i=0;i<vec.nDim;i++){
  std::cout<<vec.vectorArray[i]<<" ";
}

std::cout<<"]";
}


void print(const Matrix& mat){


for(int i=0;i<mat.nDim;i++){
  std::cout<<"[";
  for(int j=0;j<mat.sizeOfArrays;j++){
    
   std::cout<<*mat.matrixArray[i]<<" ";
  
  }
   std::cout<<"]";
  std::cout<<std::endl;
}


}


void deleteAll(Vector* vec){
delete []vec->vectorArray;
delete vec;
}
void deleteAll(const Matrix* mat){
for(int i=0;i<mat->nDim;i++){
  delete []mat->matrixArray[i];
}
delete [] mat->matrixArray;
delete mat;
}

bool addFirstToSecond(Vector& vec1, Vector& vec2){
if(vec1.nDim != vec2.nDim){
  return 0;
}
else{
  for(int i=0;i<vec1.nDim;i++){
    vec2.vectorArray[i]+=vec1.vectorArray[i];
  }
}
  return 1;
}


void setNewDimension(Vector& vec, int newSize){
vec.nDim=newSize;
}