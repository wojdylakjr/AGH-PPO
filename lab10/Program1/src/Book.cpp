#include"Book.h"
Book::Book(){}


Book::Book (const std::string &name){
  _name = name;
}


Book::~Book(){}

void Book::printName() const{
  std::cout<<_name;
}

int Book::getSize(){
  return _name.size();
}