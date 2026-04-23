#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    if (n <= 0) return 0;
    int max = 0, min = 0;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        if (i == 0) {
            max = val;
            min = val;
        } else {
            if (val > max) max = val;
            if (val < min) min = val;
        }
    }
    printf("Max: %d Min: %d\n", max, min);
    return 0;
}
