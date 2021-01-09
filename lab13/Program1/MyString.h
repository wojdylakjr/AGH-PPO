#pragma once
#include<iostream>
#include<cstring>

#define String MyString

namespace mystring{

class MyString{ 
  public:

  MyString(); 
  MyString(const char*);
  MyString(const MyString&);
  MyString(MyString&&);
  ~MyString();

  operator  char*() const;
  MyString& operator=(const char*); 

  char* getText() const;
  int getSize() const;
  void setText(const char*);
  void setSize(int);
  void print(const char*) const; 
 

  private:
  char* _text; 
  int _size; 

};

  bool operator== (const MyString&, const MyString&);
  bool operator== (const MyString&, const char*); 
  MyString operator+(const MyString&, char);
  MyString operator*(int, const MyString&);



}
