#include <stdio.h>

void linearSearch(int arr[], int size, int k) {
    int comparisons = 0;
    int foundIndex = -1;

    for (int i = 0; i < size; i++) {
        comparisons++; 
        if (arr[i] == k) {
            foundIndex = i;
            break; 
        }
    }

    if (foundIndex != -1) {
        printf("Key %d found at index %d.\n", k, foundIndex);
    } else {
        printf("Key %d not found in the array.\n", k);
    }
    printf("Total comparisons performed: %d\n", comparisons);
}

int main() {
    int data[] = {12, 45, 7, 23, 9, 56};
    int size = sizeof(data) / sizeof(data[0]);
    int key = 23;

    linearSearch(data, size, key);

    return 0;
}