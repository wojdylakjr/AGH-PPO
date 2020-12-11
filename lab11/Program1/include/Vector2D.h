#pragma once
#include <iostream>
#include <math.h>

class Vector2D{
  public:
  static int count; //zmienna statyczna opisująca ilość wektorów, inkrementowana jest w każdym konstrukotrze

  Vector2D(); //konstruktor domyślny, iniciuje _x i _y na 0
  Vector2D(const Vector2D&); //konstruktor kopiujacy
  Vector2D(Vector2D&&); //konstruktor przenoszacy
  ~Vector2D(); //destruktor

  Vector2D add(const Vector2D&) const; //metoda zwracajaca obiekt klasy Vector2D zawierajacy sumę dwóch wektorów, jako argument przyjmuje stala referencje na obiekt klasy Vector2D
  double dot(const Vector2D&) const; // meoda zwraca iloczyn skalarny typu double dwoch wektorów, jako argument przyjmuje stala referencje na obiekt klasy Vector2D
  void print(const std::string& = "") const; // metoda print typu  void wypisujaca wektor, jako argument przyjmuje stala referencje na stringa, jest to argument domniemamy domyślnie pusty string, argument wypisywany jest przed wspolrzednymi

  static Vector2D fromCarthesian(double x, double y); //metoda statyczna zwracajaca obiekt klasy Vector2D ze wspolrzednymi kartezjanskimi jako argumenty przyjmuje wartosci typu double oznaczajca wspolrzedne kartezjanskie
  static Vector2D fromPolar(double r, double phi);//metoda statyczna zwracajaca obiekt klasy Vector2D ze wspolrzednymi kartezjanskimi przliczone z wspolrzednych biegunowych jako argumenty przyjmuje wartosci typu double oznaczajca wspolrzedne biegunowe
  
  
  private:
  float _x; //prywatna skladowa klasy typu float przechowywujaca wspolrzedna x
  float _y; //prywatna skladowa klasy typu float przechowywujaca wspolrzedna y

  Vector2D(double,double); //prywatny konstruktor tworzacy obiekt klasy Vector2D jako argumenty przyjmuje dwie wspolrzedne typu double, wywyolywany jest tylko w metodach fromCarthesian i fromPolar
};