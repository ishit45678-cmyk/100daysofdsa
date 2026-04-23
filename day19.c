#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    if (n < 2) return 0;
    long long min_diff = 3000000000LL;
    int a = 0, b = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            long long sum = (long long)arr[i] + arr[j];
            long long abs_sum = sum < 0 ? -sum : sum;
            if (abs_sum < min_diff) {
                min_diff = abs_sum;
                a = arr[i];
                b = arr[j];
            }
        }
    }
    printf("%d %d\n", a, b);
    return 0;
}
