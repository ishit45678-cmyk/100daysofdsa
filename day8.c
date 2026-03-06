#include <stdio.h>

// Recursive function to calculate a to the power of b
long long power(int a, int b) {
    // Base Case: Any number to the power of 0 is 1
    if (b == 0) {
        return 1;
    }
    
    // Recursive Step: a^b = a * a^(b-1)
    return a * power(a, b - 1);
}

int main() {
    int a, b;
    
    // Reading two space-separated integers
    if (scanf("%d %d", &a, &b) == 2) {
        // We use %lld for long long to handle larger results
        printf("%lld\n", power(a, b));
    }
    
    return 0;
}