#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    
    char *str;
    str = malloc(1024 * sizeof(char));
    scanf("%s", str);
    str = realloc(str, strlen(str) + 1);
    int len = strlen(str), i;
    int arr[10];
    for(i = 0; i < 10; i++)
        arr[i] = 0;
    for(i = 0; i < len; i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            arr[(int)(str[i] - '0')]++;
        }
    }
    for(i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(str);
    return 0;}
    
