#include "BooksShelf.h"

BooksShelf::BooksShelf(int size) {
  _size = size;
  _currentSize = 0;
  _arrayOfBooks = new Book[_size];
}


BooksShelf::BooksShelf(const BooksShelf &copyBook) {
  _currentSize = copyBook._currentSize;
  _size = copyBook._size;

  _arrayOfBooks = new Book[_size];

  for (int i = 0; i < _currentSize; i++) {
    _arrayOfBooks[i] = copyBook._arrayOfBooks[i];
  }
}


BooksShelf::~BooksShelf() {
  if (_arrayOfBooks != nullptr) {
    delete[] _arrayOfBooks;
    _arrayOfBooks = nullptr;
  }
}


void BooksShelf::print() const {
  int maxStringSize = 0;
  for (int i = 0; i < _currentSize; i++) {
    if (_arrayOfBooks[i].getSize() > maxStringSize) {
      maxStringSize = _arrayOfBooks[i].getSize();
      // std::cout<<"Dlugosc stringa: "<<maxStringSize<<std::endl;
    }
  }

  for (int i = 0; i < _currentSize; i++) {
    printSpaces(maxStringSize / 2 - _arrayOfBooks[i].getSize() / 2);
    _arrayOfBooks[i].printName();
    std::cout << std::endl;
  }
}


void BooksShelf::remove(int indexToDelete) {
  if (indexToDelete >= _currentSize || indexToDelete < 0) {
    std::cout << "!!! Nie mozna usunac ksiazki spoza polki !!! (element " << indexToDelete << ")" << std::endl;
  }

  else if (indexToDelete == _currentSize - 1) {
    _currentSize--;
  }

  else {
    for (int i = indexToDelete; i < _currentSize - 1; i++) {
      _arrayOfBooks[i] = _arrayOfBooks[i + 1];
    }
    _currentSize--;
  }
}


void BooksShelf::add(Book &book) {
   _arrayOfBooks[_currentSize++] = book;
}


void BooksShelf::printSpaces(int numberOfSpaces) const {
  for (int i = 0; i < numberOfSpaces; i++) {
    std::cout << " ";
  }
}