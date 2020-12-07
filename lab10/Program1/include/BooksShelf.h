#pragma once
#include"Book.h"
//klasa przechowywujaca tablice obiektow klasy Book
class BooksShelf{
  public:
  BooksShelf(int); //konstruktor, tworzacy tablice obiektow o rozmiarze podanym jako argument wywolania
  BooksShelf(const BooksShelf&); // konstruktor kopiujacy, jako argument przyjmuje stala referencje na obiekt klasy BooksShelf
  ~BooksShelf();//destruktor, usuwa utworzona dynamicznie tablice obiektow klasy Book

  void print() const; // metoda typu void, wypisuje tytuly ksiazek w sposob wyposrodkowany, nie przyjmuje argumentow
  void remove(int); //metoda typu void usuwajaca obiekt z tablicy, jako argument przyjmuje indeks w tablicy elementu do usuniecia
  void add(Book&); //metoda typu void dodajaca obiekt klasy Book do tablicy, jako argument przyjmuje referencje na ten obiekt
  void printSpaces(int) const; //metoda typu void wypisujaca spacje, jako argument przyjmuje liczbe typu int oznaczajca ile razy ma wypisac spacje
  
  private:
  int _size;//maksymalny rozmiar tablicy obiektow typu Book
  int _currentSize;//aktualny rozmiar tablicy obiektow typu Book

  Book* _arrayOfBooks; //tablica obiektow typu Book
};
