#include "MyRegister.h"
int MyRegister::_index = 0;
const int MyRegister::sizeOfBackup = 3;

MyRegister::MyRegister(int size) {
  std::cout << "Create register with maximum size " << size << std::endl;
  _sizeOfRegister = size;
  _arrayOfGrades = new MyGrade *[_sizeOfRegister];
}

MyRegister::~MyRegister() {
  std::cout << "Delete register with " << _currentSize << "/" << _sizeOfRegister
            << " grades" << std::endl;

  for (int i = 0; i < _currentSize; i++) {
    if (_arrayOfGrades[i] != nullptr) {
      delete _arrayOfGrades[i];
      _arrayOfGrades[i] = nullptr;
    }
  }

  delete[] _arrayOfGrades;
}

void MyRegister::addGrade(MyGrade *grade) {
  if (_currentSize < _sizeOfRegister) {
    _arrayOfGrades[_index] = grade;
    _currentSize = _index + 1;
  } else {
    std::cout << "The limit of 5 grades has been reached!" << std::endl;
    delete grade;
  }
  _index++;
}

void MyRegister::addGrade(MyGrade *grade) const {
  std::cout << "Const register cannot be modyfied!" << std::endl;
  delete grade;
}

void MyRegister::showRegister() const {
  std::cout << "Register " << _currentSize << "/" << _sizeOfRegister << ": ";

  for (int i = 0; i < _currentSize; i++) {
    if (_arrayOfGrades[i] != nullptr) {
      _arrayOfGrades[i]->print();
    }
  }
  std::cout << std::endl;
}

const MyRegister *MyRegister::backup() {

  MyRegister *backup = new MyRegister(sizeOfBackup);
  for (int i = 0; i < sizeOfBackup; i++) {
    backup->_arrayOfGrades[i] = _arrayOfGrades[i]->copy();
  }
  backup->_currentSize = sizeOfBackup;
  return backup;
}
void MyRegister::clearRegister() {
  for (int i = 0; i < _currentSize; i++) {
    if (_arrayOfGrades[i] != nullptr) {
      delete _arrayOfGrades[i];
      _arrayOfGrades[i] = nullptr;
    }
  }
  _currentSize = 0;
}