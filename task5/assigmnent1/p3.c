#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    int maxlen, i, j, count = 0, maxcount = 0;

    printf("enter your name: ");
    scanf("%s", name);

    printf("enter the maximum length of your name: ");
    scanf("%d", &maxlen);

    for (i = 0; i < maxlen; i++) {
        if (name[i] == '\0') {
            break;
        }

        count = 1;

        for (j = i + 1; j < maxlen; j++) {
            if (name[j] == '\0') {
                break;
            }

            if (name[i] == name[j]) {
                count++;
            }
        }

        if (count > maxcount) {
            maxcount = count;
        }
    }

    printf("your name is: %s\n", name);
    printf("the most repeated character frequency is: %d\n", maxcount);

    return 0;
}