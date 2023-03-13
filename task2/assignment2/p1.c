#include <stdio.h>

void increment(int *y) {
    (*y)++;
}

int main() {
    int x = 10;
    void (*increment_ptr)(int *) = &increment; 

    
    (*increment_ptr)(&x);

    printf("x = %d\n", x); 

    return 0;
}