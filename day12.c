#include <stdio.h>

int main() {
    int m, n;
    
    // Read rows and columns
    if (scanf("%d %d", &m, &n) != 2) return 0;

    // Condition 1: Must be square
    if (m != n) {
        printf("Not a Symmetric Matrix\n");
        return 0;
    }

    int matrix[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Condition 2: Check if matrix[i][j] == matrix[j][i]
    int isSymmetric = 1; // Assume true
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0; // Found a mismatch
                break;
            }
        }
        if (!isSymmetric) break;
    }

    if (isSymmetric) {
        printf("Symmetric Matrix\n");
    } else {
        printf("Not a Symmetric Matrix\n");
    }

    return 0;
}