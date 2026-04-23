#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int k;
    if (scanf("%d", &k) != 1) return 0;
    if (n > 0) {
        k = k % n;
        if (k < 0) k += n;
    }
    for (int i = 0; i < n; i++) {
        int idx = (n - k + i) % n;
        if (i > 0) printf(" ");
        printf("%d", arr[idx]);
    }
    printf("\n");
    return 0;
}
