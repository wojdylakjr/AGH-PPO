#include"pesel.h"

int PeselValidator(char* peselString, int* pesel){
int sizeOfPesel = strlen(peselString);

 for(int i=0;i<sizeOfPesel;i++){
    pesel[i]=(int)peselString[i] - 48;
  }
  
 if(leapYear(getYear(pesel))==false && getMonth(pesel)==2 && getDay(pesel)==29){
 return 0;
}

else if(sizeOfPesel == 11){
 
  return 1;
}

else{
  return 0;
} 
}

void printPesel(int* pesel){
for(int i=0;i<11;i++){
  std::cout<<pesel[i];
}
}

int getCtrlNumber(int* pesel){ 
int sum=0;
int tab[]={1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
for(int i=0;i<10;i++){
sum=sum+ pesel[i]*tab[i];
}
sum=sum%10;
sum=10-sum;
sum=sum%10;
return sum;
}

char* sex(int* pesel){
if(pesel[9]%2==1){
 return (char*)"Mezczyzna";
}
else{
  return (char*)"Kobieta";
}
}

int getDay(int* pesel){
  
  int day=pesel[4]*10+pesel[5];
return day;
}

int getMonth(int* pesel){

if(pesel[2]==1 || pesel[2]==0){
 int month=pesel[2]*10+pesel[3];
 return month;
}
else if(pesel[2]==2 || pesel[2]==3){
 int month=(pesel[2]*10+pesel[3])-20;
 return month;
}
else{
 int month=(pesel[2]*10+pesel[3])-40;
 return month;
}
}

int getYear(int* pesel){

if(pesel[2]==1 || pesel[2]==0){ //1900-1999
 int year=1900+pesel[0]*10+pesel[1];
 return year;
}

else if(pesel[2]==2 || pesel[2]==3){//2000-2099
 int year=2000+pesel[0]*10+pesel[1];
 return year;
}

else{//2100-2199
 int year=2100+pesel[0]*10+pesel[1];
 return year;
}
}


bool leapYear(int year) {
 return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}