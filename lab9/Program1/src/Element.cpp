#include "Element.h"

Element::Element(const char *name) {
  int sizeOfName = std::strlen(name);
  _name = new char[sizeOfName + 1];
  strcpy(_name, name);
}

Element::~Element() {
  std::cout << "Destruktor Element: " << _name << std::endl;
  if (_name != nullptr) {
    delete[] _name;
    _name = nullptr;
  }
}

const char *Element::getName() const { return _name; }
void Element::printName() const { std::cout << _name << std::endl; }