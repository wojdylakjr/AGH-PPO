#pragma once
#include "MyGrade.h"

class MyRegister{
    public:
    MyRegister (int);
    ~MyRegister();
    void addGrade(MyGrade*);
    void addGrade(MyGrade*) const;
    void showRegister() const;
    const MyRegister* backup();
    void clearRegister();

    private:
    static const int sizeOfBackup;
    static int _index;
    MyGrade** _arrayOfGrades;
    int _sizeOfRegister;
    int _currentSize=0;

};

//  backup->_arrayOfGrades[i]->setID(_arrayOfGrades[i]->getID());
//         backup->_arrayOfGrades[i]->setGrade(_arrayOfGrades[i]->getGrade());