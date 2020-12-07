// Proszę napisać klasę Book zawierającą tytuł książki i klasę BooksShelf, przechowującą książki.
// - W klasie Book można użyć std::string (zalecane.
// - Półka (BooksShelf) ma ustaloną na początku pojemność.
// - Do półki można dodawać (metoda add) lub odejmować (metoda remove) książki.
// - Tytuły wypisywane są w sposób wyśrodkowany.

#include <iostream>
#include "BooksShelf.h"
#include "Book.h"

int main() {
  Book b1("Encyklopedia PWN");
  Book b2("O Obrotach Sfer Niebieskich");
	Book b3("Nieslychanie dlugi tytul, ktory nic nie mowi o tresci ksiazki");

  BooksShelf shelf(3);
  shelf.add(b1);
  shelf.add(b2);
  shelf.add(b3);

  shelf.print();
	std::cout << std::endl;

  const BooksShelf backup = shelf;
	shelf.remove(6); //proba usuniecia elementu spoza polki
  shelf.remove(2);

  std::cout << "========= Original shelf: =========" << std::endl;
  shelf.print();
	std::cout << std::endl;

  std::cout << "============= Backup: =============" << std::endl;
  backup.print();
}

/* //Output:
                      Encyklopedia PWN
                 O Obrotach Sfer Niebieskich
Nieslychanie dlugi tytul, ktory nic nie mowi o tresci ksiazki

!!! Nie mozna usunac ksiazki spoza polki !!! (element 6)
========= Original shelf: =========
     Encyklopedia PWN
O Obrotach Sfer Niebieskich

============= Backup: =============
                      Encyklopedia PWN
                 O Obrotach Sfer Niebieskich
Nieslychanie dlugi tytul, ktory nic nie mowi o tresci ksiazki
*/