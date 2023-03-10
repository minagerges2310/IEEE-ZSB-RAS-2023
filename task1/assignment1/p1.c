#include <stdio.h>

int main() {
    int arr[100], dup[100], n, i, j, count = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        dup[i] = -1; 
    }

    // Count the number of each element
    for (i = 0; i < n; i++) {
        count = 1;
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                dup[j] = 0; // Mark the duplicate element
            }
        }
        if (dup[i] != 0) {
            dup[i] = count;
        }
    }

    // Print the count of duplicate elements
    printf("The total number of duplicate elements in the array is: ");
    for (i = 0; i < n; i++) {
        if (dup[i] > 1) {
            printf("%d ", dup[i]);
        }
    }
    printf("\n");

    return 0;
}