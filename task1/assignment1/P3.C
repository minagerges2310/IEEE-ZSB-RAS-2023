#include <stdio.h>

void count_frequency(int arr[], int size) {
    int frequency[size];
    int i, j, count;
    
    
    for (i = 0; i < size; i++) {
        frequency[i] = 0;
    }
    
    
    for (i = 0; i < size; i++) {
        count = 1;
        for (j = i+1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                
                frequency[j] = -1;
            }
        }
      
        if (frequency[i] != -1) {
            frequency[i] = count;
        }
    }
    
    
    printf("Element\tFrequency\n");
    for (i = 0; i < size; i++) {
        if (frequency[i] != -1) {
            printf("%d\t%d\n", arr[i], frequency[i]);
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    count_frequency(arr, size);
    
    return 0;
}