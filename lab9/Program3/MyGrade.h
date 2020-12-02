#pragma once
#include<iostream>

class MyGrade{
    public:
    MyGrade (double);
    MyGrade ();
    ~MyGrade();
    void setGrade(double);
    void setID(double);
    double getGrade()const;
    double getID()const;
    void print() const;
    MyGrade* copy();
    static int numberOfGrades;

    private:
    static int nextID;
    double _grade;
    int _gradeID;

};