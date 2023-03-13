#include <stdio.h>

int main() {
  int x = 0x123456;
  int *ptr = &x;

  printf("Initial value of ptr: 0x%x\n", *ptr);

  *ptr++;
  printf("Value of ptr after *ptr++: 0x%x\n", *ptr);
  /* Explanation: The * operator has a higher precedence than the ++ operator.
  So, *ptr++ first dereferences the pointer and then increments the pointer.*/
 

  *++ptr;
  printf("Value of ptr after *++ptr: 0x%x\n", *ptr);
  /* Explanation: The ++ operator has a higher precedence than the * operator.
  So, *++ptr first increments the pointer and then dereferences it.*/


  ++*ptr;
   printf("Value of ptr after ++*ptr: 0x%x\n", *ptr);
  /* Explanation: The ++ operator has a higher precedence than the * operator.
  So, ++*ptr first dereferences the pointer and then increments the integer it points to.*/
  

  return 0;

}
