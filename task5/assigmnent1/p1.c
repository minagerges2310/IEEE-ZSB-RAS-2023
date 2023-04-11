#include <stdio.h>
#include <stdlib.h>

int main() {
   
    int* block1 = (int*) malloc(sizeof(int));
    if (block1 == NULL) {
        printf("Memory allocation using malloc failed.\n");
    } else {
        *block1 = 123;
       
        printf("Value assigned to block1: %d\n", *block1);
    }

    
    int* block2 = (int*) calloc(1, sizeof(int));
    if (block2 == NULL) {
        printf("Memory allocation using calloc failed.\n");
    } else {
        *block2 = 456;
        
        printf("Value assigned to block2: %d\n", *block2);
    }

    
    int* block3 = (int*) malloc(sizeof(int));
    if (block3 == NULL) {
        printf("Memory allocation using malloc for block3 failed.\n");
    } else {
        *block3 = 789;
        
        printf("Value assigned to block3: %d\n", *block3);

        
        block3 = (int*) realloc(block3, 2 * sizeof(int));
        if (block3 == NULL) {
            printf("Memory reallocation using realloc failed.\n");
        } else {
            *(block3 + 1) = 987;
            
            printf("Value assigned to block3 after reallocation: %d\n", *block3);
            printf("Value assigned to the newly allocated block3: %d\n", *(block3 + 1));
        }
    }

   
    free(block1);
    free(block2);
    free(block3);

    return 0;
}