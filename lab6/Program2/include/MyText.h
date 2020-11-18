#pragma once
#include<iostream>
#include<cstring>
typedef struct MyText{
    char* textName;
    int textNameSize;
    char* text;
    int textSize;
}MyText;

int my_uptolow_lowtoup(int );
MyText* initMyText(const char*);
MyText* initMyText(const char*,MyText*);
bool empty(MyText*);
int size(MyText*);
char* getCString(MyText*);
void nicePrint(MyText*);
MyText* append(MyText*, const char*);
void setChar(MyText*, int, char); 
void erase(MyText*, int, int);  
void modify(MyText*, int (func)(int));
void clear(MyText*);

