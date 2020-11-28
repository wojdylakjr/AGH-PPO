#pragma once
#include <iostream>
#include <cstring>

typedef struct Node{
  Node* next;
  char* data;
}Node;

typedef struct OneWayList{
  Node* head;
}OneWayList;



void prepare(OneWayList*); //funkcja przygotuwjaca liste, jako argument przyjmuje wskaznik na strukture OneWayList

void add(OneWayList*, const char*);//funkcja dodajaca wezel na koniec listy, jako argumenty przyjmuje wskaznik na strukture OneWayList oraz wskaznik tablice znakowa (slowo)

bool empty(const OneWayList*);//funkcja zwracajaca wartosc logiczna, jako argument przyjmuje wskaznik na strukture OneWayList, zwraca false jesli lista nie jest pusta lub true jesli lista nie ma zadnego wezla

void dump(const OneWayList*);//funkcja wypisuje tablice w kolejnosci od pierwszego do ostatniego wezla, jako argument przyjmuje wskaznik na strukture OneWayList

void clear(OneWayList*);//funkcja czyszczaca pamiec, usuwa pamiec zaalokowana w wezle na tablice znakowa oraz sam wezel, jako argument przyjmuje wskaznik na strukture OneWayList