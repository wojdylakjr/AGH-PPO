#include "MyString.h"

mystring::MyString::MyString() {}

mystring::MyString::MyString(const char *text) {
  _size = strlen(text) + 50;
  _text = new char[_size];
  strcpy(_text, text);
}

mystring::MyString::MyString(const MyString &copied) {
  _size = copied._size;
  _text = new char[_size];
  strcpy(_text, copied._text);
}

mystring::MyString::MyString(MyString &&string) {
  _text = std::__exchange(string._text, nullptr);
  _size = std::__exchange(string._size, 0);
}

mystring::MyString::~MyString() {
  if (_text != nullptr) {
    delete[] _text;
    _text = nullptr;
  }
}

mystring::MyString::operator char *() const { return _text; }

mystring::MyString &mystring::MyString::operator=(const char *text) {
  strcpy(_text, text);
  _size = strlen(text) + 50;
  return *this;
}

char *mystring::MyString::getText() const { return _text; }

int mystring::MyString::getSize() const { return _size; }

void mystring::MyString::setText(const char *text) {
  _text = (char *)text;
}

void mystring::MyString::setSize(int size) { _size = size; }

void mystring::MyString::print(const char *txt) const {
  std::cout << txt << _text << std::endl;
}

mystring::MyString mystring::operator+(const MyString &string1,
                                       const MyString &string2) {

  char *temp = new char[string1.getSize() + string2.getSize()];
  strcpy(temp, string1.getText());
  strcat(temp, string2.getText());
  MyString newString((char *)temp);
  delete[] temp;

  return newString;
}

mystring::MyString mystring::operator+(const MyString &string, char sign) {
  const char *txt = new char(sign); //it doesn't work properly
  char *text = new char[2]; // for sign and \0
  strcpy(text, txt); //valgrind error
  MyString charSign(text);
  delete txt;
  delete[] text;
  return string + charSign;
}

mystring::MyString mystring::operator*(int n, const MyString &string) {
  char *temp = new char[n * string.getSize()];
  strcpy(temp, string.getText());
  for (int i = 0; i < n - 1; i++) {
    strcat(temp, string.getText());
  }
  MyString newString(temp);
  delete[] temp;
  return newString;
}

bool mystring::operator==(const MyString &string1, const MyString &string2) {
  if (string1.getSize() != string2.getSize()) {
    return false;
  }
  return true;
}

bool mystring::operator==(const MyString &string, const char *txt) {
  return string == MyString(txt);
}