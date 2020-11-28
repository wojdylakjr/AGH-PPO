#pragma once
#include<iostream>
#include<cmath>
#include"MapDistance.h"

class MapPoint{
public:
void set_latitude(double); //metoda ustawiajaca szerokosc geograficzna obiektu, przyjmujent argument typu double
void set_longitude(double);//metoda ustawiajaca dlugosc szerokosci geograficznej obiektu, przyjmujent argument typu double
void print(); ////metoda wypisujaca obiekt klasy MapPoint
void set_coordinates(double,double);//metoda ustawiajaca dlugosc oraz szerokosc geograficzna obiektu, przyjmujent argumenty typu double
MapDistance distance(MapPoint);//funkcja zwraca typ klasy MapDistance przechowujacy odelgloscu szerokosci i dlugosci geograficznej pomiedzy przyjetym argumentem, a obiktem klasy na ktorym zostala wywyolana, przyjmuje obiekt typu klasy MapPoint
MapPoint closest(MapPoint, MapPoint);//funkcja zwraca typ klasy MapPoint przechowujacy szerokosc i dlugosc geograficzna jednego z punktow ktory jest najblizej, obiektu klasy na ktorym zostala wywyolana metoda, przyjmuje obiekty typu klasy MapPoint
MapPoint half_way_to(MapPoint);//funkcja zwraca typ klasy MapPoint przechowujacy szerokosc i dlugosc geograficzna punktu w polowie odlegosci pomiedzy otrzymanym argumentem a, obiektem klasy na ktorym zostala wywyolana metoda, przyjmuje obiekty typu klasy MapPoint

private:
double _latitude;//szerokosc geograficzna punktu
double _longitude;//dlugosc geograficzna punktu

};