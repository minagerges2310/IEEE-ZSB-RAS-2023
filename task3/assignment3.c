#include<stdio.h>
struct test
{
   int id;
   char name[50];
   char class_id;
};

int main() {
    printf("size of struct test: %ld bytes\n", sizeof(struct test));

    struct test test2 = {
        .name = "Test",
        .id = 1,
        .class_id = 'A'
    };

    printf("size of struct test after changing the order of name: %ld bytes\n", sizeof(test2));

    return 0;
    /*the size remain the same becase the total amount of memory used by the struct is the same regardless of the order*/
}