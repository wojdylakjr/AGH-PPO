#pragma once
#include<iostream>
typedef struct MyString{
 const char* str;
int size;
}MyString;

void init(MyString&,const char*);
MyString join(const MyString&, const MyString&);
void swap(MyString&, MyString&);
void swap(MyString*&, MyString*&);
void del( MyString& s, const MyString& s1=MyString{nullptr,0}, const MyString& s2 = MyString{nullptr,0},const MyString& s3 = MyString{nullptr,0}, const MyString& s4 = MyString{nullptr,0}); 