#ifndef PESEL_H
#define PESEL_H
#include <iostream>
#include <cstring>

int PeselValidator(char*, int* pesel);
void printPesel(int* pesel);
int getCtrlNumber(int* pesel);
char* sex(int* pesel);
int getDay(int* pesel); 
int getMonth(int* pesel);
int getYear(int* pesel);
bool leapYear(int year);

#endif