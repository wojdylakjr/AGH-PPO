#include"MyString.h"

int MyString::totalNumberOfStrings = 0;
const int maxSizeOfWord = 100;

MyString::MyString(){}


MyString::MyString(const char* text){
    int textSize = std::strlen(text);
    _string = new char [textSize + maxSizeOfWord];
    strcpy(_string, text);
   _numberOfString = ++ MyString::totalNumberOfStrings;
    
}


MyString::~MyString(){
    std::cout<<"- deleting " <<_string <<std::endl;
    delete [] _string;
}


const char*MyString::getString() const{
    return _string;
}

void MyString::setString(const char* text){
    strcpy(_string,text);
}

void MyString::print() const{
    std::cout<<"ID " <<_numberOfString<<".str: "<<_string<<std::endl;
}


void MyString::join(const MyString& newStr){
    std::strcat(_string, newStr._string);

}
void MyString::replace(const char* text){
    std::strcpy(_string, text);
}


MyString MyString:: create(const char* text){
    MyString newString(text);
    return newString;
}


void swap(MyString& string1, MyString& string2){
    int tempSize = strlen(string1.getString()) > strlen(string2.getString()) ? strlen(string1.getString()) : strlen(string2.getString());
    
    std::cout<<"Rozmiar wiekszego ze swpa: "<<tempSize<<std::endl;
    char* temp = new char [tempSize + maxSizeOfWord];
    std::strcpy(temp, string1.getString());
    string1.setString(string2.getString());
    string2.setString(temp);
    delete [] temp;
}