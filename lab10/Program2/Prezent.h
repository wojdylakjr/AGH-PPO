#pragma once
#include<iostream>

class Prezent{
    friend class Worek;
    public:
    Prezent (float);
    ~Prezent();

    float getPrice();
    Prezent* getNext();

    void Wypisz() const;

    
    private:
    float _price;
    Prezent* _next;
};