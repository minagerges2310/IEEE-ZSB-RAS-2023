#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

int main() {
    char input[MAX_INPUT_LENGTH];
    char stop_code[] = "!!";

    while (1) {
        printf("enter a string (enter '!!' to stop): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; 

       
        if (strcmp(input, stop_code) == 0) {
            printf("stop code entered. \n");
            break;
        }

        int frequency[256] = {0}; 
        printf("unique characters: ");
        for (int i = 0; i < strlen(input); i++) {
            if (frequency[input[i]] == 0) {
                printf("%c ", input[i]);
                frequency[input[i]]++;
            }
        }
        printf("\n");
    }

    return 0;
}