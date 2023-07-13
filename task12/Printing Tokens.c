#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *str;
    str = malloc(1024 * sizeof(char));
    scanf("%[^\n]", str);
    str = realloc(str, strlen(str) + 1);
    //Write your logic to print the tokens of the sentence here.
    for (char *c = str; *c != NULL; c++) {
    if(*c == ' '){
        *c= '\n';
    }
    }
    
    printf("%s",str);
    return 0;
}
