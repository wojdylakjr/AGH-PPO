#include "MyGrade.h"
int MyGrade::numberOfGrades = 0;
int MyGrade::nextID = 1;

MyGrade::MyGrade(double newGrade) {
  _grade = newGrade;
  _gradeID = ++numberOfGrades;
}

MyGrade::MyGrade() {}

MyGrade::~MyGrade() {
  std::cout << "Delete grade with id " << _gradeID << std::endl;
}

double MyGrade::getGrade() const { return _grade; }
void MyGrade::setGrade(double grade) { _grade = grade; }
void MyGrade::setID(double ID) { _gradeID = ID; }
double MyGrade::getID() const { return _gradeID; }

void MyGrade::print() const {
  std::cout << "[" << _gradeID << ": " << _grade << "]";
}

MyGrade *MyGrade::copy() {
  MyGrade *copiedGrade = new MyGrade();
  copiedGrade->_grade = _grade;
  copiedGrade->_gradeID = _gradeID;
  return copiedGrade;
}