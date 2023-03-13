#include <stdio.h>
void ext_fun(void);
void test(void);
int z=5;
int main(){
    auto int num1=1;
    register int num2=2;
    printf("num is %d\n",num2);
    printf("num is %d\n",num1);
     z++;
     printf("z= %d\n",z);
     test();
     test();
     ext_fun();
    
    return 0;
}

