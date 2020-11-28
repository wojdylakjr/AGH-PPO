#include "lab04.h"
void initCounter(int* n){
if(*n==0 || *n<0){
  std:: cout<<"Size must be non-zero (and positive)\n";
}
}

double* initGeometricalSequence(int a1, double q, int size){
// if(size==0){
//   std::cout<<"Nothing to print.\n";
// }
//else{
  //double* tab=new double[size];
  double* tab=(double*)malloc(sizeof(double)*size);
  tab[0]=a1;
  for(int i=1;i<size;i++){
    tab[i]=tab[i-1]*q;
  }
//}

return tab;
}

double* initArithmeticSequence(int a1, double r, int size){
//double* tab=new double[size];
double* tab=(double*)malloc(sizeof(double)*size);
  tab[0]=a1;
  for(int i=1;i<size;i++){
    tab[i]=tab[i-1]+r;
  }
  return tab;
}

void printSequence(const double* tab, int size){
if(size==0){
 std::cout<<"Nothing to print.\n";
}
else{
  std::cout<<"(";
  for(int i=0;i<size;i++){
    std::cout<<tab[i];
    if(i<size-1) std::cout<<",";
  }
  std::cout<<")\n";
}

}

void deleteSequence(const double** tab){
if(*tab == NULL){
 std::cout<<"Nothing to delete.\n";
}
else{
  //delete [](tab);
   free((void*)*tab);
   *tab=NULL;
  std::cout<<"Sequence deleted.\n";
}
}

void addSequence(const double*** list, double** listLength, double* tab, int size){
   //int sizeOfList=(size/3)+1;
   static int sizeOfList=1;

  if(sizeOfList==1){
  *list=(const double**)malloc(sizeof(double*)*sizeOfList);
  *listLength=(double*)malloc(sizeof(double)*sizeOfList);
  }
  else{
    *list=(const double**)realloc(*list,sizeof(double*)*sizeOfList);
  *listLength=(double*)realloc(*listLength,sizeof(double)*sizeOfList);
  }

  (*listLength)[sizeOfList-1]=size;
  (*list)[sizeOfList-1]=tab;
  


  sizeOfList++;

}

void printAllSequences(const double** list, double* listLenght){
 
  for(int i=0;i<6;i++){
   printSequence(list[i],(int)listLenght[i]);
  }

}

void deleteAllSequences (const double** list, double* tab){
free(list);
free(tab);
}