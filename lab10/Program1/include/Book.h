#pragma once
#include <iostream>
class Book{
  public:
  Book(); //konstruktor domyslny
  Book (const std::string &); //konstruktor, ktory jako argument przyjmuje nazwe ksiazki
  ~Book();//destruktor

  void printName() const; //metoda typu void wypisujaca nawe ksiazki, nie przyjmuje argumentow
  int getSize(); //metoda zwracajaca liczbe typu int oznaczajaca dlugosc tytulu
  
  private:
  std::string _name; //nazwa ksiazki (tytul)
};