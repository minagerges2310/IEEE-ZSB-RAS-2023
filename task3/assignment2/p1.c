#include <stdio.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
};

int main() {
    struct Date date1, date2;

  
    char date1_str[11];  
    printf("enter date 1 (in dd/mm/yyyy format): ");
    scanf("%s", date1_str);
    sscanf(date1_str, "%d/%d/%d", &date1.day, &date1.month, &date1.year);

    
    char date2_str[11];
    printf("enter date 2 (in dd/mm/yyyy format): ");
    scanf("%s", date2_str);
    sscanf(date2_str, "%d/%d/%d", &date2.day, &date2.month, &date2.year);

  
    if (date1.day == date2.day && date1.month == date2.month && date1.year == date2.year) {
        printf("Dates are equal\n");
    } else {
        printf("Dates are not equal\n");
    }

    return 0;
}