#include "studList.h"

StudList::StudList(const char *name) {
  int sizeOfName = std::strlen(name);
  _listName = new char[sizeOfName + 1];
  strcpy(_listName, name);
  _head = nullptr;
  _tail = nullptr;
}


StudList::~StudList() {
  if (_listName != nullptr) {
    std::cout << "Destruktor StudList" << _listName << std::endl;
    delete[] _listName;
    _listName = nullptr;
  }
}


const char *StudList::getName() const { return _listName; }


void StudList::prepend(Element *newNode) {
  newNode->_next = _head;
  if (_head == nullptr) {
    _head = newNode;
    _tail = _head;
    _head->_next = nullptr;
  } else {
    _head = newNode;
  }
}


void StudList::prepend(const char *name) {
  Element *newNode = new Element(name);
  prepend(newNode);
}


Element *StudList::getHead() const { return _head; }


Element *StudList::getTail() const { return _tail; }


bool StudList::isEmpty() const {
  if (_head == nullptr) {
    return true;
  }
  return false;
}


void StudList::print() const {
  if (_listName != nullptr) {
    if (_head != nullptr) {
      std::cout << _listName << " = [";
      Element *temp = _head;
      while (temp->_next != nullptr) {
        std::cout << temp->_name << " ";
        temp = temp->_next;
      }
      std::cout << temp->_name << "]" << std::endl;
    } else {
      std::cout << _listName << " = []" << std::endl;
    }
  }
}


Element *StudList::getLast() {
  if (_head == NULL) {
    return nullptr;
  }
  Element *prev = _head;
  Element *current = _head;
  while (current->_next != nullptr) {
    prev = current;
    current = current->_next;
  }
  Element *last = prev->_next;
  prev->_next = nullptr;

  return last;
}


void StudList::clearList() {
  if (_head != nullptr && _head->_next != nullptr) {
    Element *current = _head;
    Element *next = _head->_next;
    while (next != nullptr) {
      delete current;
      current = next;
      next = next->_next;
    }
    delete current;
    current = nullptr;
    _head = nullptr;
  }
  if (_head != nullptr && _head->_next == nullptr) {
    std::cout << "To sie nie usuwa" << std::endl;
  }
}


void StudList::removeLast() {
  if (_head != nullptr && _head->_next != nullptr) {
    Element *prev = _head;
    Element *current = _head;
    while (current->_next != nullptr) {
      prev = current;
      current = current->_next;
    }
    Element *last = prev->_next;
    delete last;
    prev->_next = nullptr;
  } else if (_head != nullptr && _head->_next == nullptr) {
    delete _head;
    _head = nullptr;
  }
}