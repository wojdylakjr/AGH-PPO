#pragma once
#include<iostream>
//klasa MapDistance przechowuje informacje o różnicy pomiędzy długościami geograficznymi dwóch punktów oraz różnicy pomiędzy szerokościami geograficznymi tych samych punktów
class MapDistance{ 
  public:
  void print(); //metoda wypisujaca obiekt klasy MapDistance
  void set_latitudeDistance(double);//metoda ustawiajaca odleglosc szerokosci geograficznej obiektu, przyjmujent argument typu double
  void set_longitudeDistance(double);//metoda ustawiajaca odleglosc dlugosci geograficznej obiektu, przyjmujent argument typu double
  double get_latitudeDistance();//metoda zwracajaca odleglosc szerokosci geograficznej obiektu
 double get_longitudeDistance();//metoda zwracajaca odleglosc dlugosci geograficznej obiektu
  private:
  double _latitudeDistance; //odelglosc szerokosci geograficznej
  double _longitudeDistance;//odelglosc dlugosci geograficznej

};