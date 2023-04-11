#include <stdio.h>

int main() {
    int input_time;
    int hours, minutes, seconds;

    printf("enter the time in the format [hh:mm:ss]: ");
    scanf("%d:%d:%d", &hours, &minutes, &seconds);

    
    input_time = hours * 10000 + minutes * 100 + seconds;

    printf("\nInput time: %02d:%02d:%02d\n", hours, minutes, seconds);
    printf("Time stored in integer variable: %d\n", input_time);

    
    hours = input_time / 10000;
    minutes = (input_time / 100) % 100;
    seconds = input_time % 100;

    printf("Time extracted from integer variable: %02d:%02d:%02d\n", hours, minutes, seconds);

    return 0;
}