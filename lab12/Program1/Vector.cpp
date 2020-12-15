#include "Vector.h"

Vector::Vector (int size){
    _sizeOfVector = size;
    _vector = new double[_sizeOfVector];
    for(int i = 0; i < _sizeOfVector; i++){
        _vector[i] = 0;
    }
}


Vector::Vector (const Vector& copiedVector){
    _sizeOfVector = copiedVector._sizeOfVector;
    _vector = new double[_sizeOfVector];
    for(int i = 0; i < _sizeOfVector; i++){
        _vector[i] = copiedVector._vector[i];
    }
}


Vector::Vector (Vector&& movedVector){
    _sizeOfVector = movedVector._sizeOfVector;
    _vector = new double[_sizeOfVector];
    for(int i = 0; i < _sizeOfVector; i++){
        _vector[i] = std::__exchange(movedVector._vector[i], 0);
    }
}


Vector::operator double() const{
    return norm();
}


Vector::~Vector(){
    delete [] _vector;
    _sizeOfVector = 0;
    _vector = nullptr;
}


Vector Vector::sum(const Vector& firstVector, const Vector& secondVector){
    if(firstVector._sizeOfVector == secondVector._sizeOfVector){
        double sum = 0;
        Vector summedVector(firstVector._sizeOfVector);

        for(int i = 0; i < firstVector._sizeOfVector; i++){
            summedVector._vector[i] += firstVector._vector[i] + secondVector._vector[i];
        }
        return summedVector;
    
    }
    else{
        std::cout << "Nie mozna wyliczc sumu :(" << std::endl;
        return 0;
    }    
}


Vector Vector::sum(const Vector& firstVector, int number){
    double sum = 0;
    Vector summedVector(firstVector._sizeOfVector);

    for(int i = 0; i < firstVector._sizeOfVector; i++){
        summedVector._vector[i] += firstVector._vector[i] + number;
    }

    return summedVector; 
}


double Vector::dot(const Vector& firstVector, const Vector& secondVector){
    if(firstVector._sizeOfVector == secondVector._sizeOfVector){
        double dot = 0;
        for(int i = 0; i < firstVector._sizeOfVector; i++){
            dot += firstVector._vector[i] * secondVector._vector[i];
        }
        return dot;
    }
    else{
        std::cout << "Nie mozna wyliczc iloczynu :(" << std::endl;
        return 0;
    }
    
}


double& Vector::at(int index){
    return _vector[index];
}


void Vector::print (const std::string& text) const{
    std::cout<<text<<"(";
    for(int i = 0; i < _sizeOfVector - 1; i++){
        std::cout << _vector[i]<<",";
    }
   std::cout << _vector[_sizeOfVector - 1] << ")" << std::endl;
}


double Vector::norm() const{
    double squareSum = 0;
    for(int i = 0; i < _sizeOfVector; i++){
        squareSum += _vector[i] *_vector[i];
    }
    return sqrt(squareSum);
}