#include <stdio.h>

#define ADD(x, y) (x + y)
#define SUBTRACT(x, y) (x - y)

int main() {
    int a, b;
    char operation;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    printf("Enter '+' or '-' to perform addition or subtraction: ");
    scanf(" %c", &operation);

    switch(operation) {
        case '+':
            printf("Result of addition: %d\n", ADD(a, b));
            break;
        case '-':
            printf("Result of subtraction: %d\n", SUBTRACT(a, b));
            break;
        default:
            printf("Invalid operation.\n");
    }

    return 0;
}