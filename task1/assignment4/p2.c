#include<stdio.h>
#include<string.h>
int main(){
    char x[100];
    printf("enter your string");
    fgets(x,sizeof(x),stdin);
    printf("the chars is:\n");

    for (int i=0; i<strlen(x); i++){
        printf("%c\n", x[i]);
    }
    return 0;
}