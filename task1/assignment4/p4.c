#include<stdio.h>
int main() {
    char x[100], y[100];
    int i;

    printf("enter a string: ");
    scanf("%s", x);

   
    for (i = 0; x[i] != '\0'; i++) {
        y[i] = x[i];
    }
    y[i] = '\0';

    printf("the string copied is: %s\n", y);

    return 0;
}