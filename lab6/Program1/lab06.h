#pragma once
#include <iostream>


typedef struct Bits{
  int size;
  int bitsArray[32]={0};
}Bits;

void 	set(Bits*, int*, int); //funkcja przygtowuje strukture Bits, jako argumenty przyjmuje pusta strukture bits, tablice i rozmiar tablicy
void print (const Bits*); //funkcja wypisujaca strukture, jako argument przyjmuje strukture bits
const Bits add_up(Bits*,Bits*);//funkcja sumujaca dwie liczby binarne przechowywane w strukturach Bits,jako argumenty przyjmuje struktury bits, zwraca strukture z wynikiem
void bit_and(Bits*,Bits*);//funkcja liczaca koniunkcje dwoch liczb binarnych,jako argumenty przyjmuje struktury bits, gdzie druga to maska
void bit_xor(Bits*, Bits*);//funkcja liczaca alternatywa wykluczajaca dwoch liczb binarnych,jako argumenty przyjmuje struktury bits, gdzie druga to maska
int to_decimal(const Bits*);//funkcja zamienia liczbe w postaci binarnej na decymalna.;jako argument przyjmuje strukture bits, a zwraca liczbe decymalna