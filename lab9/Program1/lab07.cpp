#include"lab07.h"

Vector* form_Vector(int a, int b){
Vector *vec = new Vector;

return vec;
}

const Matrix* form_Matrix(int a, int b, int c){
const Matrix* mat = new Matrix;
return mat;
}

void print(Vector){

}
void print(const Matrix){

}
void deleteAll(Vector* vec){
delete vec;
}
void deleteAll(const Matrix* mat){
delete mat;
}
bool addFirstToSecond(Vector&, Vector&){
return 0;
}
void setNewDimension(Vector&, int){

}