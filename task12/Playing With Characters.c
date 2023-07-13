#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
char ch;

char ch1[100];

char str[100];

scanf("%c", &ch);

scanf("%s", &ch1);

scanf("\n");

scanf("%[^\n]%*c", &str);

printf("%c\n", ch);

printf("%s\n", ch1);

printf("%s", str);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
