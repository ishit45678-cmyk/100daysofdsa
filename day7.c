#include <stdio.h>

// Recursive function to find the n-th Fibonacci number
int fib(int n) {
    // Base cases: fib(0) = 0, fib(1) = 1
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    // Recursive step: fib(n) = fib(n-1) + fib(n-2)
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;

    // Taking input from the user
    if (scanf("%d", &n) == 1) {
        // Printing the result
        printf("%d\n", fib(n));
    }

    return 0;
}