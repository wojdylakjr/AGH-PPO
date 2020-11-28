#include "lab03.h"

void printArray(myArray array){
  if(array.N==0){
    std :: cout<<"Cannot print empty array.\n";
  }
  else{
    std :: cout<<"[";
    for(int i=0;i<array.N;i++){
      std :: cout<<array.tab[i];
      if(i<array.N-1){
        std :: cout<<",";
      }
    }
    std :: cout<<"]";
  }

}

int fillArrayWithFibonacci(myArray* array, int n){
  
  if(n==0){
    std :: cout<<"Wrong number of dimensions.\n";
    return 0;
  }
  else if(array==NULL){
     std :: cout<<"Empty pointer provided.\n";
     return 0;
  }   
  else{
    array->N = n;
    for(int i=0;i<n;i++){
      array->tab[i]=generateFibonaci(i);//podejrzewam, ze tu moze byc cos nie tak
    }
    return 1;
  } 

}
void extend(myArray* array, int a){
  if(a+array->N>50){
    std :: cout<<"Wow, you've just gone crazy ("<<a+array->N<<">50).\n";
  }
  else{
    array->N = array->N+a;
  }
   printArray(*array);
  std :: cout<<"(extending by "<<a<<" done)\n";

}
void truncate(myArray* array, int a){
    if(array->N-a<0){
    std :: cout<<"Wow, you've just gone crazy ("<<array->N-a<<"<0).\n";
  }
  else{
    array->N = array->N-a;
  }
   printArray(*array);
  std :: cout<<"(truncation by "<<a<<" done)\n";

}
void revert(myArray* array){
  for(int i=0; i<(array->N)/2;i++){
    swap(&array->tab[i], &array->tab[array->N-i-1]);
  }
  printArray(*array);
  std :: cout<<"(reverting done)\n";

}

void checkArraySpouse(myArray* array){
  if(array->adress==NULL){
    printArray(*array);
    std :: cout<<"  has no spouse)\n";
  }
  else{
    printArray(*array);
    std :: cout<<" is paired with ";
     printArray(*array->adress);

  }

}
void marry(myArray* firstArray, myArray* secondArray){
  // if(firstArray->N==secondArray->N){
  //   std :: cout<<"Can't marry my twin\n";
  // }
   if(firstArray->adress==secondArray->adress){
       std :: cout<<"Can't marry myself\n";
  }
  else{
    firstArray->adress=secondArray;
    secondArray->adress=firstArray;
  }  

}
void divorce(myArray*, myArray*){

}
myArray formChild(myArray* firstArray, myArray* secondArray){
  if(firstArray==NULL || secondArray ==NULL){
    exit 1;
  }
return *firstArray;
}
void printParents(myArray* array){

}

int generateFibonaci(int n){
if(n==0 || n==1) return 1;
else return generateFibonaci(n-1)+generateFibonaci(n-2);
}

void swap(int *a, int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}