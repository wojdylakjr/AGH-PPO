#include "Worek.h"

Worek::Worek() { _head = nullptr; }

Worek::~Worek() {}

void Worek::test(){
    _head->_next->_next->Wypisz();
}

void Worek::UsunPrezentNumer(int indexToDelete) {
  Prezent *temp = _head;
  if (indexToDelete == 1) {
    _head = _head->_next;
   // _head->_next = nullptr;
  }
    else {
        int index = 2;
        while (index != indexToDelete) {
            temp = temp->_next;
            index++;
        }
        if (temp->_next != nullptr) temp->_next = temp->_next->_next;
//   if (temp->_next->_next == nullptr) {
//     temp->_next = nullptr;
//   } else {
        
//   }
    }
}

void Worek::WypiszZawartosc() const {
  std::cout << "=== Zawartosc worka ===" << std::endl;

  Prezent *temp = _head;
  int i = 1;
  while (temp != nullptr) {
    std::cout << i++ << ". ";
    temp->Wypisz();
    temp = temp->_next;
  }
}

void Worek::Wloz(Prezent newPresent) {
  if (_head == nullptr) {
    _head = &newPresent;
    _head->_next = nullptr;
  } else {
    Prezent *temp = _head;
    while (temp->_next != nullptr) {
      temp = temp->_next;
    }
    temp->_next = &newPresent;
    temp->_next->_next = nullptr;
    // std::cout<<temp->getPrice()<<std::endl;
  }
}