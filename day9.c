#include <stdio.h>
#include <string.h>

void mirrorCodeName(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;
    char temp;

    while (left < right) {
        // Swap characters
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        // Move pointers inward
        left++;
        right--;
    }
}

int main() {
    char codeName[1001]; // Assuming max length of 1000

    // Read the string (stops at whitespace/newline)
    if (scanf("%s", codeName) == 1) {
        mirrorCodeName(codeName);
        printf("%s\n", codeName);
    }

    return 0;
}