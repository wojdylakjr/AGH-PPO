#include "lab06.h"
#include <iostream>
#include <math.h>

void 	set(Bits* bits, int* data, int size){
  bits->size=size;
  for(int i=0;i<bits->size;i++){
    bits->bitsArray[i]=data[i];
  }
}

void print (const Bits* bits){
  
for(int i=0;i<bits->size;i++){
  std::cout<<bits->bitsArray[i];
}
std::cout<< std::endl;
}

const Bits add_up(Bits* bits1,Bits* bits2){
  Bits sum;
  int maxSize;
  if(bits1->size > bits2->size) {
    maxSize=bits1->size;
  }else{
       maxSize=bits2->size;
  }
  sum.size=maxSize;
  
  int addInt=0;
  int count=0;

   for(int i=maxSize-1;i>=0;i--){
     
    
     count=bits1->bitsArray[i]+bits2->bitsArray[i] + addInt;
     if(count==0 || count==1){
         sum.bitsArray[i]=count;
         addInt=0;
       
     }
     if(count==2){
       sum.bitsArray[i]=0;
       addInt=1;
     }
       if(count==3){
       sum.bitsArray[i]=1;
       addInt=1;
     }
     
     count=0;



}

  return sum;

}

void bit_and(Bits* bits, Bits* mask){
  for(int i=0;i<bits->size;i++){
    bits->bitsArray[i] = mask->bitsArray[i] & bits->bitsArray[i];
  }

}

void bit_xor(Bits* bits, Bits* mask){
    for(int i=0;i<bits->size;i++){
      if((bits->bitsArray[i]==1 &&  mask->bitsArray[i]==0) ||(bits->bitsArray[i]==0 &&  mask->bitsArray[i]==1) ){
        bits->bitsArray[i]=1;
      }
      else{
          bits->bitsArray[i]=0;
      }
 
  }

}

int to_decimal(const Bits* bits){
  int number=0;
  int counter=0;
  for(int i=bits->size-1;i>=0;i--){
  
  number = number + pow(2, counter)*bits->bitsArray[i];
  counter++;
  }
  
  return number;
}