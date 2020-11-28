#pragma once
#include"Element.h"
#include<cstring>


class StudList{
  public:
  StudList (const char*); //konstruktor ustawiajacy nazwe listy _listName, jako argument przyjmuje nazwe wezle jako typ const char*, kkonstruktor nic nie zwraca
  ~StudList();//destruktor
  const char* getName()const; //getter zwracajacy nazwe listy _listName jako typ const char*
  void prepend(const char*); //metoda dodajaca kolejny element na poczatek listy, jako argument przyjmuje nazwe wezle jako typ const char*
  void prepend(Element*);//przeciazona metoda prepend, jako argument przyjmuje wskaznik na utworzony juz wezel
  Element* getHead()const;//metoda zwracajaca wskaznik na obiekt klasy Element, ktory jest pierwszym elementem listy (headem)
  Element* getTail()const;//metoda zwracajaca wskaznik na obiekt klasy Element, ktory jest ostatnim elementem listy (tailem)
  bool isEmpty()const;//metoda sprawdzajaca czy lista jest pusta, zwraca typ logiczny bool
  void print()const;//drukuje listę w postaci [w1, w2, w3]
  Element* getLast();//pobiera ostatni element, usuwając go z listy, ale nie zwalniając pamięci oraz zwraca wskaznik na ten element
  void clearList();//usuwa wszystkie elementy z listy, włącznie ze zwolnieniem pamięci, ale nie usuwa samej listy
  void removeLast();//usuwa ostatni element z listy wraz z dealokacją pamięci obiektu typu Element


  private:
  char* _listName;//nazwa listy
  Element* _head;//wskaznik na pierwszy element (wezel) listy
  Element* _tail;//wskaznik na ostatni element (wezel) listy
};

