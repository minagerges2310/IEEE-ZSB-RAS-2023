#include <stdio.h>
#include <stdlib.h>

#define SORT_ASCENDING 1
#define SORT_DESCENDING 2

int* sort_array(int arr[], int size, int sort_type) {
    int i, j, temp;
    for(i = 0; i < size - 1; i++) {
        for(j = i + 1; j < size; j++) {
            if((sort_type == SORT_ASCENDING && arr[i] > arr[j]) || (sort_type == SORT_DESCENDING && arr[i] < arr[j])) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

#ifdef SORT_ASCENDING
    #define SORT_FUNCTION sort_array(arr, size, SORT_ASCENDING)
    #endif
#ifdef SORT_DESCENDING
    #define SORT_FUNCTION sort_array(arr, size, SORT_DESCENDING)
#endif

int main() {
    int size, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d integers:\n", size);
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int* sorted_arr = SORT_FUNCTION;
    printf("Sorted array:\n");
    for(i = 0; i < size; i++) {
        printf("%d ", sorted_arr[i]);
    }
    printf("\n");

    return 0;
}