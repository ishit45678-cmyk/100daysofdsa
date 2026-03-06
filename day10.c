#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char s[1001]; // Assuming max length of 1000
    
    // Read the string
    if (scanf("%s", s) != 1) return 0;

    int i = 0;
    int j = strlen(s) - 1;
    bool isPalindrome = true;

    while (i < j) {
        if (s[i] != s[j]) {
            isPalindrome = false;
            break; // No need to check further
        }
        i++;
        j--;
    }

    if (isPalindrome) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}