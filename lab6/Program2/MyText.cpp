#include "MyText.h"
#include <string.h>

int my_uptolow_lowtoup(int letter) {
  if (letter < 97) {
    return std::tolower(letter);
  } else {
    return std::toupper(letter);
  }
}

MyText *initMyText(const char *string) {
  //MyText *textStructure= new MyText;
  MyText *textStructure = (MyText *)malloc(sizeof(MyText));
  textStructure->text = nullptr;
  textStructure->textNameSize = strlen(string);
  //textStructure->textName = new char[textStructure->textNameSize + 1];
 textStructure->textName = (char *)malloc((textStructure->textNameSize + 1) * sizeof(char));
  strcpy(textStructure->textName, string);

  return textStructure;
}

MyText *initMyText(const char *name, MyText *sourceTextStructure) {
  MyText *textStructure = (MyText *)malloc(sizeof(MyText));
  textStructure->textNameSize = strlen(name);
  textStructure->textName = (char *)malloc((textStructure->textNameSize + 1) * sizeof(char));
  strcpy(textStructure->textName, name);

  textStructure->textSize = sourceTextStructure->textSize;
  textStructure->text = (char *)malloc((textStructure->textSize + 1) * sizeof(char));
  strcpy(textStructure->text, sourceTextStructure->text);

  return textStructure;
}

bool empty(MyText *textStructure) {
  if (textStructure->text == nullptr) {
    return true;
  } else {
    return false;
  }
}

int size(MyText *textStructure) { 
    return textStructure->textSize; 
}

char *getCString(MyText *textStructure) {
  if (textStructure->text == nullptr) {
    return (char *)"";
  } else {
    return (char *)textStructure->text;
  }
}

void nicePrint(MyText *textStructure) {
  if (textStructure != nullptr) {
    std::cout << textStructure->textName << " = " << textStructure->text<< std::endl;
  } 
}

MyText *append(MyText *textStructure, const char *string) {
  if (textStructure->text == nullptr) {
    textStructure->textSize = strlen(string);
    //textStructure->text = new char[textStructure->textSize + 1];
    textStructure->text = (char *)malloc((textStructure->textSize + 1) * sizeof(char));
    strcpy(textStructure->text, string);
  } else {
    textStructure->textSize += strlen(string);
    textStructure->text = (char *)realloc(textStructure->text, (textStructure->textSize + 1) * sizeof(char));
    strcat(textStructure->text, string);
  }

  return textStructure;
}

void setChar(MyText *textStructure, int position, char letter) {
  textStructure->text[position] = letter;
}

void erase(MyText *textStructure, int startIndex, int stopIndex) {
  int i = 0;
  for (i = startIndex; i < stopIndex + 1; i++) {
    textStructure->text[i] = textStructure->text[i + startIndex - 1];
  }
  textStructure->text[i] = '\0';
  textStructure->textSize = stopIndex + 1;
}

void modify(MyText *textStructure, int(func)(int)) {
  for (int i = 0; i < textStructure->textSize; i++) {
    textStructure->text[i] = func(textStructure->text[i]);
  }
}

void clear(MyText *textStructure) {
  if (textStructure->textName != NULL && textStructure->text != NULL) {
    free(textStructure->textName);
    free(textStructure->text);
    textStructure->textName = NULL;
    textStructure->text = NULL;
  }
}