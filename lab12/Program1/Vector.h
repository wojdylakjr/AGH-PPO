#pragma once
#include <iostream>
#include <cmath>

class Vector{
    public:
    Vector (int);
    Vector (const Vector&);
    Vector (Vector&&);
    ~Vector();

    explicit operator double() const;

    static Vector sum(const Vector&, const Vector&);
    static Vector sum(const Vector&, int);
    static double dot(const Vector&, const Vector&);

    double& at(int index);
    void print (const std::string& = "") const;
    double norm() const;
    
    private:
    int _sizeOfVector;
    double *_vector;
};