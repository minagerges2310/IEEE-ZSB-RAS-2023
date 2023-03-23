#include <stdio.h>
#include <string.h>

struct student_info {
    unsigned int roll:4;
    unsigned int age:8;
    unsigned int marks:3;
    char name[20]; // 20 characters with 8 bits each
    char address[30]; // 30 characters with 8 bits each
} students[15];

void print_info(int n) {
    printf("Student %d:\n", n+1);
    printf("Roll Number: %d\n", students[n].roll);
    printf("Age: %d\n", students[n].age);
    printf("Marks: %d\n", students[n].marks);
    printf("Name: %s\n", students[n].name);
    printf("Address: %s\n", students[n].address);
    printf("--------------------\n");
}

int main() {
    memset(students, 0, sizeof(students)); // initialize all fields to 0

    // populate the struct with data
    for (int i = 0; i < 15; i++) {
        students[i].roll = i+1;
        students[i].age = 18 + i;
        students[i].marks =  (i % 50); // generate random marks between 60 and 99
        strcpy(students[i].name, "ahmed");
        strcpy(students[i].address, "33 abo malak st");
    }

    // print all the info
    for (int i = 0; i < 15; i++) {
        print_info(i);
    }

    printf("Size of student_info: %lu bytes\n", sizeof(struct student_info));
    return 0;
}
 
 //the processor will deal with each member of the stract with the given bit field as it will occupie only the bits that its allowed to