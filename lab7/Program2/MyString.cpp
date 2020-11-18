#include "MyString.h"
#include <cstring>


void init(MyString& string, const char* text){ 
   
    string.size=strlen(text);
    string.str=new char[string.size+1];
    strcpy((char*)string.str,text);   

}

MyString join(const MyString& string1, const MyString& string2){

MyString string;
char* buffer= new char[string1.size + string2.size + 1];
strcpy(buffer, string1.str);
strcat(buffer, string2.str);
string.str=buffer;
return string;
}

void swap(MyString& string1, MyString& string2){
 char *buffer;
 buffer=(char*)string1.str;
 string1.str=string2.str;
 string2.str=buffer;
}

void swap(MyString*& string1, MyString*& string2){

// const char *buffer;
//  buffer=string1->str;
//  string1->str=string2->str;
//  string2->str=buffer;  

 MyString *temp;
  temp=string1;
  string1=string2;
  string2=temp;

}

void del( MyString& s,const  MyString& s1, const MyString& s2 ,const MyString& s3, const MyString& s4 ){
if(s.str !=nullptr){
std::cout<<"deleting "<<s.str<<std::endl; 
delete [] s.str;
s.str=nullptr;
}

if(s1.str !=nullptr){
std::cout<<"deleting "<<s1.str<<std::endl; 
delete [] s1.str;
s.str=nullptr;
}

if(s2.str !=nullptr){
std::cout<<"deleting "<<s2.str<<std::endl; 
delete [] s2.str;
s.str=nullptr;
}
if(s3.str !=nullptr){
std::cout<<"deleting "<<s3.str<<std::endl; 
delete [] s3.str;
s.str=nullptr;
}
if(s4.str !=nullptr){
std::cout<<"deleting "<<s4.str<<std::endl; 
delete [] s4.str;
s.str=nullptr;
}




}