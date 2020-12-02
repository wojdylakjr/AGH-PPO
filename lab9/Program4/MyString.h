#pragma once
#include<cstring>
#include<iostream>

class MyString{
    public:
    MyString();
    MyString(const char*);
    ~MyString();
    const char* getString() const;
    void setString(const char*);
    void print() const;
    void join(const MyString&);
    void replace(const char*);
    static MyString create(const char*);
    
    private:
    static int totalNumberOfStrings;
    int _numberOfString;
    char* _string;

};


 void swap(MyString&, MyString&);