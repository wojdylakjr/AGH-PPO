#pragma once
#include <cstring>
#include <iostream>
//klasa element przechowujaca prywatne pola nazwy wezła w liscie typu char* oraz wskaznik na nastepny wezel w liscie
class Element{
  public:
  friend class StudList;//teraz klasa StudList ma dostep do prywatnych skladowych klasy Element
  Element(const char*); //konstruktor ustawiajacy nazwe wezla _name, jako argument przyjmuje nazwe wezle jako typ const char*, kkonstruktor nic nie zwraca
  ~Element();//destruktor
  const char* getName()const;//getter zwracajacy nazwe wezla jako typ const char*
  void printName()const;//metoda wypisujaca liste
  private:
  char* _name;//nazwa wezla listy jednokierunkowej
  Element* _next;//wskaznik na nastepny wezel listy jednokierunkowej

};