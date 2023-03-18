#include<stdio.h>
struct test
{
   int id;
   char name[50];
   char class_id;
};

struct test2
{
    char name[50];
    int id;
    char class_id;
};


int main() {
    printf("size of struct test: %ld bytes\n", sizeof(struct test));



    printf("size of struct test after changing the order of name: %ld bytes\n", sizeof(struct test2));

    return 0;
    /*the size of the struct change as a result of padding as when we start with char then int an additional space is taken for char */
}
