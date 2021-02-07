#pragma once 
#include<iostream>
#include <functional>

class FVec{
    public:
    FVec(int, int);
    FVec(std::function<int(int)>,int);
    FVec(const FVec&);
    FVec(FVec&&);
    ~FVec();

    FVec& set(int,int);
    int begin()const;
    int end()const;
    


    friend std::ostream& operator<< (std::ostream& , const FVec &);
    int& operator[](int);
    FVec& operator=(const FVec&);
    FVec& operator=(FVec&&);


    static FVec create (int);

    private:
    int _size;
    int _begin;
    int _end;
    int *_arr;

    void copy(const FVec&);
    void move(FVec&&);
    //konstruktor prywatny wywolywany w create
};