#include"Prezent.h"


Prezent::Prezent (float price){
    _price = price;
    _next = nullptr;
}
Prezent:: ~Prezent(){}

float Prezent::getPrice(){
    return _price;
}

Prezent* Prezent::getNext(){
    return _next;
}

void Prezent::Wypisz() const{
      std::cout<<"Prezent o wartosci: " << _price << std::endl;
}