#include <stdio.h>

void reverseArray(int arr[], int n) {
    int left = 0;        
    int right = n - 1;    
    int temp;

    while (left < right) {
       
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;


        left++;
        right--;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Original array: ");
    printArray(data, n);

    reverseArray(data, n);

    printf("Reversed array: ");
    printArray(data, n);

    return 0;
}