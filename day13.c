#include <stdio.h>

int main() {
    int r, c;
    if (scanf("%d %d", &r, &c) != 2) return 0;

    int matrix[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;
    int first = 1; // To manage spacing in output

    while (top <= bottom && left <= right) {
        // 1. Move Right across the top row
        for (int i = left; i <= right; i++) {
            printf("%s%d", first ? "" : " ", matrix[top][i]);
            first = 0;
        }
        top++;

        // 2. Move Down the rightmost column
        for (int i = top; i <= bottom; i++) {
            printf(" %d", matrix[i][right]);
        }
        right--;

        // 3. Move Left across the bottom row (if row still exists)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                printf(" %d", matrix[bottom][i]);
            }
            bottom--;
        }

        // 4. Move Up the leftmost column (if column still exists)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf(" %d", matrix[i][left]);
            }
            left++;
        }
    }
    printf("\n");

    return 0;
}