#include "lab01.h"

void printVec (vecN* vector){
if(vector->N == 0){
  std:: cout<<"Cannot print empty vector.\n";
}
else{
 std:: cout<< "[";
 for(int i=0;i<vector->N;i++){
   std:: cout<<vector->tab[i];
   if(i<vector->N -1){
     std:: cout<<",";
     }
 }
 std:: cout<< "]";
 }
}


int generateFibonacci(int n){
 if(n==1 || n==2) return 1;
 else return generateFibonacci(n-1) + generateFibonacci(n-2); 
}

int fillVecWithFibonacci(vecN* vector, int numberOfFibonacci){
  if(vector==NULL){
    std:: cout<< "Empty pointer provided.\n";
    return 0;
  }
  else if(numberOfFibonacci<1){
    std:: cout<< "Wrong number of dimensions.\n";
    return 0;
  }
  else{
    vector->N=numberOfFibonacci;
    for(int i=0;i<numberOfFibonacci;i++){
     vector->tab[i]=generateFibonacci(i+1);
    }
   return 1;
  }
}


void revert (vecN * vector){
  for(int i=0;i<vector->N/2;i++){
    int size=vector->N;
    swapNumbers(&vector->tab[i], &vector->tab[size-i-1]);
  }
   printVec(vector);
   std::cout<<"(reverting done)\n";

//  int *tempTab = (int*) malloc(vector->N * sizeof(int ));
//  for(int i=0;i<vector->N;i++){
//    tempTab[i]=vector->tab[i];
//  }
//   for(int i=vector->N;i>=0;i--){
//    vector->tab[i]=tempTab[vector->N-i-1];
//  }
//  printVec(vector);
//  free(tempTab); Not a good idea, i don't have to create a new tab 
}


void truncate (vecN * vector,int a){
   if(a>50){
    std::cout<<"Wow, you've just gone crazy ("<<a<<">50).\n";
  }
  else{
    vector->N=vector->N - a;
    printVec(vector);
    std::cout<<"(truncation done).\n";
  }
}


void extend (vecN *vector,int a){
 if(a>50){
    std::cout<<"Wow, you've just gone crazy ("<<a<<">50).\n";
  }
  else{
    vector->N=vector->N + a;
    printVec(vector);
    std::cout<<"(extendtion done).\n";
  }
}


void checkVecSpouse(vecN * vector){
  if(vector->adress==NULL){
    printVec(vector);
    std::cout<<" has no spouse\n";
  }
  else{
   printVec(vector);
   std::cout<<" is paired with ";
   printVec(vector->adress);
   std::cout<<"\n";
  }
}


void marry (vecN* firstVector,vecN* secondVector){
 if(firstVector==secondVector){
   std::cout<<"Can't marry myself.\n";
 }
 else if(firstVector->N==secondVector->N){
    int i=0;
    while(i<firstVector->N){
      if(firstVector->tab[i]==secondVector->tab[i]){
       i++;
      }
      else{
        return;
      }
      if(i==firstVector->N){
        std::cout<<"Can't marry my twin.\n";
      }
    }
  }
 else{
   firstVector->adress=secondVector;
   secondVector->adress=firstVector;
 }
}


void divorce (vecN* firstVector,vecN* secondVector){
  firstVector->adress=NULL;
  secondVector->adress=NULL;
}


void swap(vecN* firstVector,vecN* secondVector){
 vecN tempVector = *firstVector;
 *firstVector=*secondVector;
 *secondVector=tempVector;
}

void swapNumbers (int *a, int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}
//mam problem z generowaniem liczb ciagu 
// bo pierwsze dwa wyrazy (a nie tylko pierwszy) wynoszą 1. //dwa wyrazy, a nie tylko drugi. //no wiecej juz nie pomoge... po protstu nie moge, a chcialbym. blad jest na pewno caly cas w l. 21
//rozuminem, dziekuje