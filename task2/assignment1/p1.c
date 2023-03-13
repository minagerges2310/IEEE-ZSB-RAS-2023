#include <stdio.h>

int main() {
  

  int *p1;
  char *p2;
  long long *p3;
  printf("p1 =%d\n",p1);
  p1++;
  printf("p1++ =%d\n",p1);

  printf("p2 =%d\n",p2);
  p2++;
  printf("p2++ =%d\n",p2);

  printf("p3 =%d\n",p3);
  p3++;
  printf("p3++ =%d\n",p3);


  return 0;
}