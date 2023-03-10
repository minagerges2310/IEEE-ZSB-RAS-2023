#include <stdio.h>
void add(int *a,int *b, int *sum){
    *sum = *a + *b;
}
int main(){
int x,y,tot;
printf("enter two numbers");
scanf("%d %d",&x,&y);
add(&x,&y,&tot);
printf("the sum of the numbers is %d",tot);
return 0;
}
