#pragma once
#include"Prezent.h"

class Worek{
    public:
    Worek();
    ~Worek();

    void UsunPrezentNumer(int);
    void WypiszZawartosc() const;
    void Wloz(Prezent);

    void test();

    private:
    Prezent *_head;
};