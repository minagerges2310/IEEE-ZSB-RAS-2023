#include<stdio.h>

struct student_info
{
    int roll_num;
    char name[50];
    int age;
    char address[100];
    float marks;
    
};
int print_student_info(struct student_info students[]){
    int count=0;
      int student_num=15;
    printf("students info");
    for (int i = 0; i <student_num; i++)
    {
       printf("Student %d:\n", i+1);
        printf("Roll Number: %d\n", students[i].roll_num);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Address: %s\n", students[i].address);
        printf("Marks: %.2f\n\n", students[i].marks);
    }
    int num_faild=0;
    printf("students who failed: \n");
    for (int i = 0; i < student_num; i++)
    {
        if(students[i].marks < 12.0){
            printf("student %d (roll number%d)\n", i+1,students[i].roll_num);
            num_faild++;
        }  
    }
    printf("number of failed students%d",num_faild);


}

int main(){
    int student_num =15;
struct student_info students[student_num];
for(int i=0; i<student_num; i++){
        printf("enter the student info %d\n" ,i+1);
        printf("enter roll number: ");
        scanf("%d",&students[i].roll_num);

        printf("enter name: ");
        scanf("%s",&students[i].name);

        printf("enter age: ");
        scanf("%d",&students[i].age);

        printf("enter address: ");
        scanf("%s",&students[i].address);

        printf("enter the mark:");
        scanf("%f", &students[i].marks);


     }

print_student_info(students);

   
}