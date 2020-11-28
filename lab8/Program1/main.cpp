// Proszę napisać klasę MapPoint, która reprezentuje punkt na kuli ziemskiej składający się z długości (longitude) i szerokości (latitude) geograficznej  (położenie na półkuli północnej/południowej lub wschodniej/zachodniej reprezentowane jest przez znak szerokości i długości geograficznej).

// Metoda print klasy MapPoint wypisuje na ekran, że jest to punkt i podaje jego współrzędne w nawiasach okrągłych.
// Metoda set_coordinates ustawia szerokość i dlugość geograficzna punktu na podstawie argumentów, które przyjmuje.
// Metoda distance w klasie MapPoint zwraca obiekt typu MapDistance, który przechowuje informacje o różnicy pomiędzy długościami geograficznymi dwóch punktów oraz różnicy pomiędzy szerokościami geograficznymi tych samych punktów.
// Metoda closest zwraca punkt będący najbliżej punktu na rzecz którego została wywołana metoda. Odległość pomiędzy punktami należy obliczyc jako pierwiastek sumy kwadratów różnic, czyli
// r = sqrt(delta_dlugosc*delta_dlugosc + delta_szerokosc*delta_szerokosc)
// Funkcja obliczająca pierwiastek to 'double sqrt(double)' i znajduje się w bibliotece "cmath".
#include <iostream>
#include "MapDistance.h"
#include "MapPoint.h"
#include "MapPoint.h"
#include "MapDistance.h"

int main() {
  using std::cout;

  cout<<"========== KRK ==========\n";
  MapPoint krk;
  krk.set_latitude(19.938333);
  krk.set_longitude(50.061389);
  krk.print();

  cout<<"========== NYC ==========\n";
  const double nyc_latitude = 40.7127;
  const double nyc_longitude = -74.0059;
  MapPoint nyc;
  nyc.set_coordinates (nyc_latitude, nyc_longitude);
  nyc.print();

  cout<<"========== PORTO & IRKUTSK ==========\n";
  MapPoint porto;
  porto.set_coordinates(41.162142, -8.621953);
  porto.print();
  MapPoint irkutsk;
  irkutsk.set_coordinates(52.283333, 104.283333);
  irkutsk.print();

  cout<<"========== DISTANCE ==========\n";
  MapDistance nyc_porto = nyc.distance(porto);
  nyc_porto.print();

  cout<<"========== CLOSEST ==========\n";
  krk.closest(porto, irkutsk).print();

  cout<<"========== SOMEWHERE ==========\n";
  krk.half_way_to(nyc).print();

  return 0;
}
/* Output:
========== KRK ==========
Point: (19.9383, 50.0614)
========== NYC ==========
Point: (40.7127, -74.0059)
========== PORTO & IRKUTSK ==========
Point: (41.1621, -8.62195)
Point: (52.2833, 104.283)
========== DISTANCE ==========
Distance: (0.449444, 65.3839)
========== CLOSEST ==========
Point: (41.1621, -8.62195)
========== SOMEWHERE ==========
Point: (30.3255, -11.9723)
*/
