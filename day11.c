#include <stdio.h>

int main() {
    int m, n;

    // Read dimensions: m rows and n columns
    if (scanf("%d %d", &m, &n) != 2) return 0;

    int matrix1[m][n];
    int matrix2[m][n];

    // Read the first matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Read the second matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Calculate sum and print the result immediately
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int sum = matrix1[i][j] + matrix2[i][j];
            
            // Print space between elements, but not after the last element in a row
            printf("%d%s", sum, (j == n - 1) ? "" : " ");
        }
        printf("\n");
    }

    return 0;
}