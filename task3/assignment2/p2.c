#include<stdio.h>
struct info
{
   char name[50];
   int age;
};

int main(){
    struct info person1 = {"ahmed", 25};
    struct info *ptr=&person1;
    printf("name: %s\n", ptr->name);
    printf("age: %d\n", ptr->age);

    return 0;


}