#include <stdio.h>

// Define enum for arithmetic operations
enum op {
    ADD = '+',
    SUB = '-',
    MUL = '*',
    DIV = '/',
    AND = '&',
    OR = '|',
    NOT = '!'
};

int main() {
    int op1, op2;
    char op_char;
    enum op operation;

    // Read inputs from user
    printf("enter the first number: ");
    scanf("%d", &op1);
    printf("enter the sucound number: ");
    scanf("%d", &op2);
    printf("Enter operation (+,-,*,/,&,|,!): ");
    scanf(" %c", &op_char);

    // Check operation using enum
    switch(op_char) {
        case ADD:
            operation = ADD;
            break;
        case SUB:
            operation = SUB;
            break;
        case MUL:
            operation = MUL;
            break;
        case DIV:
            operation = DIV;
            break;
        case AND:
            operation = AND;
            break;
        case OR:
            operation = OR;
            break;
        case NOT:
            operation = NOT;
            break;
        default:
            printf("Invalid operation!\n");
            return 1;
    }

    // Perform arithmetic operation
    int result;
    switch(operation) {
        case ADD:
            result = op1 + op2;
            break;
        case SUB:
            result = op1 - op2;
            break;
        case MUL:
            result = op1 * op2;
            break;
        case DIV:
            result = op1 / op2;
            break;
        case AND:
            result = op1 & op2;
            break;
        case OR:
            result = op1 | op2;
            break;
        case NOT:
            result = !op1;
            break;
    }

    // Print result
    printf("Result: %d\n", result);

    return 0;
}

//the size will not change as the size of enum is the size of int however the size will change if the assigned values of the new member exceed the size of int