#include <stdio.h>

void mergeLogs(int logA[], int sizeA, int logB[], int sizeB, int mergedLog[]) {
    int i = 0; // Pointer for logA
    int j = 0; // Pointer for logB
    int k = 0; // Pointer for the result array

    
    while (i < sizeA && j < sizeB) {
        if (logA[i] <= logB[j]) {
            mergedLog[k] = logA[i];
            i++;
        } else {
            mergedLog[k] = logB[j];
            j++;
        }
        k++;
    }

    while (i < sizeA) {
        mergedLog[k++] = logA[i++];
    }

    while (j < sizeB) {
        mergedLog[k++] = logB[j++];
    }
}

int main() {
    int logServer1[] = {101, 105, 110};
    int logServer2[] = {102, 108, 115, 120};
    
    int n1 = 3, n2 = 4;
    int mergedResult[n1 + n2];

    mergeLogs(logServer1, n1, logServer2, n2, mergedResult);

    printf("Chronological Log: ");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", mergedResult[i]);
    }
    
    return 0;
}