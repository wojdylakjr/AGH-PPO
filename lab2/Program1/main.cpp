#include <iostream>
#include "lab01.h"


int main(){

  std::cout << "\n>> Let's start it!" << std::endl;
  vecN a;
  printVec(&a);
  std::cout << ">> OK, I forgot to define the number of dimensions. What about now?" << std::endl;
  a.N = 5;
  printVec(&a);

  std::cout << "\n\n>> So far, so good... Do you remember recursion? Try it with Fibonacci." << std::endl;
  vecN b;
  std::cout << (fillVecWithFibonacci(0, 18) ? "OK!" : "Trying again.") << std::endl;
   std::cout << (fillVecWithFibonacci(&b, 0) ? "OK!" : "One more time.") << std::endl;
   std::cout << (fillVecWithFibonacci(&b, 18) ? "OK!" : "I give up.") << std::endl;
   printVec(&b);

  std::cout << "\n\n>> Let's try to do some fancy staff." << std::endl;
  revert(&b);
  extend(&b, 218);
  extend(&b, 2);
  truncate(&b, 4);
  revert(&b);
  truncate(&b, 10);

  std::cout << "\n>> What if the two vectors couple? Let's check it." << std::endl;
  checkVecSpouse(&a);
  checkVecSpouse(&b);
  std::cout << ">> Will you marry me?" << std::endl;
  marry(&a, &a);
  std::cout << ">> Again, will you marry me?" << std::endl;
  vecN c = a;
  marry(&a, &c); 
  std::cout << ">> Last time, will you marry me?" << std::endl;
  marry(&a, &b);
  checkVecSpouse(&a);
  checkVecSpouse(&b);
  std::cout << ">> \"It's your fault! I quit!\"" << std::endl;
  divorce(&a, &b);
  checkVecSpouse(&a);
  checkVecSpouse(&b);

  std::cout << "\n>> Last thing. Can you swap?" << std::endl;
  printVec(&a); std::cout << " is at " << &a << std::endl;
  printVec(&b); std::cout << " is at " << &b << std::endl;
  swap(&a, &b);
  std::cout << ">> After swap:" << std::endl;
  printVec(&a); std::cout << " is at " << &a << std::endl;
  printVec(&b); std::cout << " is at " << &b << std::endl;

}


/*
Output:

>> Let's start it!
Cannot print empty vector.
>> OK, I forgot to define the number of dimensions. What about now?
[0,0,0,0,0]

>> So far, so good... Do you remember recursion? Try it with Fibonacci.
Empty pointer provided.
Trying again.
Wrong number of dimensions.
One more time.
OK!
[1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584]

>> Let's try to do some fancy staff.
[2584,1597,987,610,377,233,144,89,34,55,21,13,8,5,3,2,1,1] (reverting done)
Wow, you've just gone crazy (218>50).
[2584,1597,987,610,377,233,144,89,34,55,21,13,8,5,3,2,1,1,0,0] (extending by 2 done)
[2584,1597,987,610,377,233,144,89,34,55,21,13,8,5,3,2] (truncation by 4 done)
[2,3,5,8,13,21,55,89,34,144,233,377,610,987,1597,2584] (reverting done)
[2,3,5,8,13,21] (truncation by 10 done)

>> What if the two vectors couple? Let's check it.
[0,0,0,0,0] has no spouse.
[2,3,5,8,13,21] has no spouse.
>> Will you marry me?
Can't marry myself
>> Again, will you marry me?
Can't marry my twin
>> Last time, will you marry me?
[0,0,0,0,0] is paired with [2,3,5,8,13,21]
[2,3,5,8,13,21] is paired with [0,0,0,0,0]
>> "It's your fault! I quit!"
[0,0,0,0,0] has no spouse.
[2,3,5,8,13,21] has no spouse.

>> Last thing. Can you swap?
[0,0,0,0,0] is at 0x7ffd8c907ab0
[2,3,5,8,13,21] is at 0x7ffd8c907910
>> After swap:
[2,3,5,8,13,21] is at 0x7ffd8c907ab0
[0,0,0,0,0] is at 0x7ffd8c907910

*/