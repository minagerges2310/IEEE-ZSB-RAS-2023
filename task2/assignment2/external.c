#include <stdio.h>

void test(void){
    int num3=3;
    static int num4=4;
    num3++;
    printf("num3 is %d\n",num3);
    num4++;
    printf("num4 is %d\n",num4);
    return 0;
}

