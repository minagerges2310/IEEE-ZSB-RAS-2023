#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory using malloc
    int* block1 = (int*) malloc(sizeof(int));
    if (block1 == NULL) {
        printf("Memory allocation using malloc failed.\n");
    } else {
        *block1 = 123;
       
        printf("Value assigned to block1: %d\n", *block1);
    }

    // Allocate memory using calloc
    int* block2 = (int*) calloc(1, sizeof(int));
    if (block2 == NULL) {
        printf("Memory allocation using calloc failed.\n");
    } else {
        *block2 = 456;
      
        printf("Value assigned to block2: %d\n", *block2);
    }

    // Allocate memory using realloc
    int* block3 = (int*) malloc(sizeof(int));
    if (block3 == NULL) {
        printf("Memory allocation using malloc for block3 failed.\n");
    } else {
        *block3 = 789;
       
        printf("Value assigned to block3: %d\n", *block3);

        // Free memory for block3
        free(block3);
        printf("Memory freed for block3.\n");

        // Allocate memory for block4 with a bigger space
        int* block4 = (int*) malloc(2 * sizeof(int));
        if (block4 == NULL) {
            printf("Memory allocation using malloc for block4 failed.\n");
        } else {
            *block4 = 111;
            *(block4 + 1) = 222;
            printf("Memory allocated successfully using malloc for block4.\n");
            printf("Value assigned to block4: %d, Value assigned to the next block of block4: %d\n", *block4, *(block4 + 1));
        }
    }

    // Free the allocated memory
    free(block1);
    free(block2);
    free(block3);

    return 0;
}
// by doing can lead to memory fragmentation and may cause the program to run out of memory or crash