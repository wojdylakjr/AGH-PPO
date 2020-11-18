#pragma once
#include<iostream>
#include<cstring>
typedef struct Node{
Node* next;
char* data;
}Node;

typedef struct MyList{
Node* head;
}Mylist;

void prepare(MyList*);
void add(MyList*, const char*);
bool empty(const MyList*);
void dump(const MyList*);
void clear(MyList*);